LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- Stepper Driver should take a input counter vector and only pulse when it is equal to the rate divider
ENTITY MaxStepperDriver IS
	GENERIC(N: integer := 24);
	PORT
	(
			clock    : in std_logic;
			nRST : in std_logic;
			pul		: OUT STD_LOGIC ;
			RAMP_RATE : in std_logic_vector(N - 1 downto 0);
			START_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_COUNT : in std_logic_vector(N - 1 downto 0)
	);
END MaxStepperDriver;


ARCHITECTURE SYN OF MaxStepperDriver IS
	SIGNAL pulCounterSig : STD_LOGIC_VECTOR (N-1 DOWNTO 0);
	SIGNAL counterSig	: STD_LOGIC_VECTOR (N-1 DOWNTO 0);
	SIGNAL rateSig : STD_LOGIC_VECTOR(N-1 DOWNTO 0);
	
	COMPONENT Counter
		PORT (
			clock		: IN STD_LOGIC ;
			q			: OUT STD_LOGIC_VECTOR (N-1 DOWNTO 0);
			inc_i       : in    std_logic_vector(N-1 downto 0);
			nRST     : IN STD_LOGIC;
			en       : IN STD_LOGIC
	);
	END COMPONENT;
	COMPONENT RampGenerator 
		PORT(
			RAMP_RATE : in std_logic_vector(N - 1 downto 0);
			START_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_COUNT : in std_logic_vector(N - 1 downto 0);
			CUR_COUNT  : in std_logic_vector(N - 1 downto 0);
			OUT_RATE : out std_logic_vector(N - 1 downto 0);
			CLK : in std_logic;
			nRST : in std_logic
		);
	END COMPONENT;
BEGIN
	COUNTER1: Counter
		PORT MAP (
			clock => clock,
			q => counterSig,
			inc_i => rateSig,
			nRST => nRST,
			en => '1'
		);
	
	COUNTER2: Counter
		PORT MAP (
			clock => counterSig(N-1),
			q => pulCounterSig,
			inc_i => "000000000000000000000001",
			nRST => nRST,
			en => '1'
		);
		
	ramp1 : RampGenerator
	PORT MAP(
		RAMP_RATE => RAMP_RATE,
		START_RATE => START_RATE,
		TARG_RATE => TARG_RATE,
		TARG_COUNT => TARG_COUNT,
		CUR_COUNT => pulCounterSig,
		OUT_RATE => rateSig,
		CLK => clock,
		nRST => nRST
		
	
	);
	
	
	
	pul <= counterSig(N-1) after 10ns;
	
END SYN;