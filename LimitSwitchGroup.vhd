
LIBRARY ieee;
USE ieee.std_logic_1164.all;
    use ieee.numeric_std.all;


ENTITY LimitSwitchGroup IS
	generic (NUM_SWITCH : integer := 24);
	PORT
	(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC_VECTOR(NUM_SWITCH - 1 downto 0);
		D       : in    STD_LOGIC_VECTOR(NUM_SWITCH - 1 downto 0);
		nRST  : IN STD_LOGIC
	);
END LimitSwitchGroup;


ARCHITECTURE SYN OF LimitSwitchGroup IS

	COMPONENT Debounce
	generic (NUM_CYCLE : integer := 10000;
				N : integer := 16);
	PORT
	(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC;
		D       : in    STD_LOGIC;
		nRST  : IN STD_LOGIC
	);
	END COMPONENT;

BEGIN
	G1: for I in 0 to NUM_SWITCH - 1 generate 
	L: Debounce
	port map(
		clock => clock,
		q => q(I),
		D => D(I),
		nRST => nRST
	);
	end generate;
END SYN;
