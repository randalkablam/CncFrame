
LIBRARY ieee;
USE ieee.std_logic_1164.all;
    use ieee.numeric_std.all;


ENTITY Debounce IS
	generic (NUM_CYCLE : integer := 10000;
				N : integer := 16);
	PORT
	(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC;
		D       : in    STD_LOGIC;
		nRST  : IN STD_LOGIC
	);
END Debounce;


ARCHITECTURE SYN OF Debounce IS

	component DFlipFlop
	port(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC;
		D       : in    STD_LOGIC;
		nRST  : IN STD_LOGIC;
		en    : IN STD_LOGIC
	);
	end component;

	component Counter
		generic(N: integer := 16);

	port(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC_VECTOR (N - 1 DOWNTO 0);
		inc_i       : in    std_logic_vector(N-1 downto 0);
		nRST  : IN STD_LOGIC;
		en    : IN STD_LOGIC
	);
	end component;


	signal FF1_OUT : std_logic;
	signal FF2_OUT : std_logic;

	signal COUNTER_OUT : std_logic_vector(N - 1 DOWNTO 0);
	
	signal COMP_SIG : std_logic;

BEGIN
	FF1 : DFlipFlop
	port map
	(
	   clock => clock,
		q => FF1_OUT,
		D => D,
		nRST => nRST,
		en => '1'
	);

	FF2 : DFlipFlop
	port map
	(
	   clock => clock,
		q => FF2_OUT,
		D => FF1_OUT,
		nRST => nRST,
		en => '1'
	);

	Counter1 : Counter
	generic map(N => 16)
	port map(
		clock => clock,
		q => COUNTER_OUT,
		inc_i => x"0001",
		nRST => not (FF1_OUT xor FF2_OUT),
		en => not COMP_SIG
	);
	
	FF3 : DFlipFlop
	port map
	(
	   clock => clock,
		q => q,
		D => FF2_OUT,
		nRST => nRST,
		en => COMP_SIG
	);
	COMP_SIG <= '1' when unsigned(COUNTER_OUT) = to_unsigned(NUM_CYCLE, N) else '0';
	
END SYN;
