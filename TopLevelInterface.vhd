

USE work.Common.all;
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
--use IEEE.std_logic_signed.all;
--use IEEE.std_logic_unsigned.all;
use ieee.numeric_std.ALL;

entity TopLevelInterface is
generic(
	NUM_SERVO : integer := 6;
	NUM_STEPPER : integer := 10
);
port (
	clk : in std_logic;
	SDA : inout std_logic;
	SCL : inout std_logic;
	pulses	: out STD_LOGIC_VECTOR (15 DOWNTO 0);
	stepperEn : out std_logic_vector(9 downto 0);
	stepperDir : out std_logic_vector(9 downto 0);
	limitSwitchIn : in std_logic_vector(23 downto 0);
	servoFeedbackIO : in std_logic_vector(5 downto 0);
	relayControl : out std_logic_vector(3 downto 0);
	UART_TX : in std_logic;
	UART_RX : in std_logic
);
end TopLevelInterface;

architecture SYN of TopLevelInterface is

	component StepperGroup
		PORT
		(
				clock    : in  STD_LOGIC;
				pulses	: out STD_LOGIC_VECTOR (9 DOWNTO 0);
				startRateMap : in RateMap(9 DOWNTO 0);
				targRateMap : in RateMap(9 DOWNTO 0);
				rampRateMap : in RateMap(9 DOWNTO 0);
				targCountMap : in CountMap(9 DOWNTO 0);
				rampEnMap : in std_logic_vector(9 DOWNTO 0)			
		);
	end component;

	
	component ServoGroup is
	port (
		clk : in std_logic;
		onTimes : in OnTypeMap(NUM_SERVO - 1 downto 0);
		nRstMap : in std_logic_vector(NUM_SERVO - 1 downto 0);
		pulseOuts : out std_logic_vector(NUM_SERVO - 1 downto 0)
	);
	end component;
	
	
	COMPONENT ConfigProcessor
	PORT (
		MCLK : in std_logic;
		nRST : in std_logic;
		SCL  : inout std_logic;
		SDA : inout std_logic;
		START_RATES: out RateMap(9 DOWNTO 0);
		TARG_RATES: out RateMap(9 DOWNTO 0);
		TARG_RAMPS: out RateMap(9 DOWNTO 0);
		TARG_COUNTS: out CountMap(9 DOWNTO 0);	
		RAMP_EN : out std_logic_vector(9 DOWNTO 0);
		STEP_DIR : out std_logic_vector(9 downto 0);
		SERVO_ON_TIME : out OnTypeMap(5 downto 0);
		SERVO_EN : out std_logic_vector(5 downto 0)
		);	
		
	END COMPONENT;
	
	
	COMPONENT LimitSwitchGroup IS
		generic (NUM_SWITCH : integer := 24);
		PORT
		(
			clock		: IN STD_LOGIC ;
			q		: OUT STD_LOGIC_VECTOR(NUM_SWITCH - 1 downto 0);
			D       : in    STD_LOGIC_VECTOR(NUM_SWITCH - 1 downto 0);
			nRST  : IN STD_LOGIC
		);
	END COMPONENT;
	
	COMPONENT GpioReader IS
	generic(NUM_GPIO : integer := 32);
	port(			
		MCLK : in std_logic;
		nRST : in std_logic;
		SCL  : inout std_logic;
		SDA : inout std_logic;
		GPIO_VEC : in ByteArray((NUM_GPIO / 8) - 1 downto 0)
	);
	END COMPONENT;
	
		COMPONENT Counter
		generic(N: integer := 5);
		PORT (
			clock		: IN STD_LOGIC ;
			q			: OUT STD_LOGIC_VECTOR (N-1 DOWNTO 0);
			inc_i       : in    std_logic_vector(N-1 downto 0);
			nRST     : IN STD_LOGIC;
			en       : IN STD_LOGIC
		);
		END COMPONENT;
		
SIGNAL startRateMapSig : RateMap(9 DOWNTO 0);
SIGNAL targRateMapSig : RateMap(9 DOWNTO 0);
SIGNAL rampRateMapSig : RateMap(9 DOWNTO 0);
SIGNAL targCountMapSig : CountMap(9 DOWNTO 0);
SIGNAL rampEnMapSig : std_logic_vector(9 DOWNTO 0);
SIGNAL servoOnTimeMapSig : OnTypeMap(NUM_SERVO - 1 DOWNTO 0);
SIGNAL servoEnMapSig : std_logic_vector(NUM_SERVO - 1 DOWNTO 0);


SIGNAL limitSwitchDebouncedMap : std_logic_vector(23 downto 0);

signal nRST : std_logic;
signal mclk : std_logic;
signal counterSig : std_logic_vector(4 downto 0);
begin

	nRST <= '1';

	stepperEn <= not rampEnMapSig;
	
--	
	GpioReader1 : GpioReader
	PORT MAP (
		MCLK => clk,
		nRST => nRST,
		SCL  => SCL,
		SDA => SDA,
		GPIO_VEC(0) => limitSwitchDebouncedMap(7 downto 0),
		GPIO_VEC(1) => limitSwitchDebouncedMap(15 downto 8),
		GPIO_VEC(2) => limitSwitchDebouncedMap(23 downto 16),
		GPIO_VEC(3) => (others => '0')
	);
	
	StepperGroup1 : StepperGroup
	port map(
		clock => mclk,
		pulses => pulses(9 downto 0),
		startRateMap => startRateMapSig,
		targRateMap => targRateMapSig,
		rampRateMap => rampRateMapSig,
		targCountMap => targCountMapSig,
		rampEnMap => rampEnMapSig
	);

	ServoGroup1 : ServoGroup
	port map(
		clk => mclk,
		onTimes => servoOnTimeMapSig,
		nRstMap => servoEnMapSig,
		pulseOuts => pulses(15 downto 10)
	);
	
	LimitGroup1 : LimitSwitchGroup
	port map (
		clock => mclk,
		q => limitSwitchDebouncedMap,
		D => limitSwitchIn,
		nRST => nRST
	);
	

	
	ConfigProcessor1: ConfigProcessor
	PORT MAP (
		MCLK => mclk,
		nRST => nRST,
		SCL  => SCL,
		SDA => SDA,
		TARG_RATES => targRateMapSig,
		TARG_RAMPS => rampRateMapSig,
		START_RATES => startRateMapSig,
		TARG_COUNTS => targCountMapSig,
		RAMP_EN => rampEnMapSig,
		SERVO_ON_TIME => servoOnTimeMapSig,
		SERVO_EN => servoEnMapSig,
		STEP_DIR => stepperDir
	);

		COUNTER1: Counter
		GENERIC MAP (N => 5)
		PORT MAP (
			clock => clk,
			q => counterSig,
			inc_i => "00001",
			nRST => nRST,
			en => '1'
		);
	
	mclk <= clk;--counterSig(4);
	
end SYN;