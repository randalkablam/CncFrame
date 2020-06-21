LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY RampGenTestBench IS
	GENERIC(N: integer := 24);
end RampGenTestBench;

ARCHITECTURE behavior OF RampGenTestBench IS

	signal clockSig : std_logic := '0';
	SIGNAL pulCounterSig : STD_LOGIC_VECTOR (N-1 DOWNTO 0);
	SIGNAL counterSig	: STD_LOGIC_VECTOR (N-1 DOWNTO 0);
   signal rateSig : std_logic_vector(23 downto 0) := (others => '0');

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
	COMPONENT Counter
		PORT (
			clock		: IN STD_LOGIC ;
			q			: OUT STD_LOGIC_VECTOR (N-1 DOWNTO 0);
			inc_i       : in    std_logic_vector(N-1 downto 0);
			nRST     : IN STD_LOGIC
	);
	END COMPONENT;
	
	BEGIN
	ramp1 : RampGenerator
	PORT MAP(
		RAMP_RATE => "000000000000000010000010",
		START_RATE => "000000000000000000000000",
		TARG_RATE => "000000000000010000011000",
		TARG_COUNT => "000000000000000010010000",
		CUR_COUNT => pulCounterSig,
		OUT_RATE => rateSig,
		CLK => clockSig,
		nRST => '1'
		
	
	);

		clockSig <= not clockSig after 50ns;
		

			COUNTER1: Counter
		PORT MAP (
			clock => clockSig,
			q => counterSig,
			inc_i => rateSig,
			nRST => '1'
		);
	
	COUNTER2: Counter
		PORT MAP (
			clock => counterSig(N-1),
			q => pulCounterSig,
			inc_i => "000000000000000000000001",
			nRST => '1'
		);
		
	
	END;
	
