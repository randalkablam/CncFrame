LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.Common.all;

ENTITY ServoTestBench IS
	GENERIC(N: integer := 24;
				NUM_SERVO : integer := 6);
end ServoTestBench;

ARCHITECTURE behavior OF ServoTestBench IS

	signal clockSig : std_logic := '0';

	
	component ServoGroup is
	port (
		clk : in std_logic;
		onTimes : in OnTypeMap(NUM_SERVO - 1 downto 0);
		nRstMap : in std_logic_vector(NUM_SERVO - 1 downto 0);
		pulseOuts : out std_logic_vector(NUM_SERVO - 1 downto 0)
	);
	end component;
	
SIGNAL servoOnTimeMapSig : OnTypeMap(NUM_SERVO - 1 DOWNTO 0);
SIGNAL servoEnMapSig : std_logic_vector(NUM_SERVO - 1 DOWNTO 0);
signal nRST : std_logic;
signal servopulses : std_logic_vector(NUM_SERVO - 1 downto 0);
	
	BEGIN

			
		clockSig <= not clockSig after 5ns;
		
	ServoGroup1 : ServoGroup
	port map(
		clk => clockSig,
		onTimes => servoOnTimeMapSig,
		nRstMap => servoEnMapSig,
		pulseOuts => servopulses
	);
		
		
		
	servoEnMapSig <= (others => '0') after 50ns,(others => '1') after 100ns;
	servoOnTimeMapSig(0) <= x"8000";
	servoOnTimeMapSig(1) <= x"0800";
	servoOnTimeMapSig(2) <= x"0080";
	servoOnTimeMapSig(3) <= x"0008";
	servoOnTimeMapSig(4) <= x"8004";
	servoOnTimeMapSig(5) <= x"0002";

	END;
	
