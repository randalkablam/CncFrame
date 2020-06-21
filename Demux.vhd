-- Demux Entity
USE work.Common.all;
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;


ENTITY Demux IS
GENERIC(
	NUM_IN : integer := 135
);
PORT (
	clk : in std_logic;
	control : in unsigned;
	input : std_logic_vector(7 downto 0);
	outputs : out ByteArray(NUM_IN - 1 downto 0)
);
END Demux;


ARCHITECTURE SYN of Demux IS
signal synch1 : std_logic_vector(7 downto 0);
signal synch2 : std_logic_vector(7 downto 0);

COMPONENT DFlipFlop IS
	PORT
	(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC;
		D       : in    STD_LOGIC;
		nRST  : IN STD_LOGIC;
		en    : IN STD_LOGIC
	);
END COMPONENT;
BEGIN
	pclk : process (clk)
	begin
	if(clk'event and clk = '1') then
		outputs(to_integer(control)) <= input; -- synch2;
	end if;
	end process;
	
--	G1: for I in 0 to 7 generate
--		L: DFlipFlop
--	port map(
--		clock => clk,
--		q => synch1(I),
--		D => input(I),
--		nRST => '1',
--		en => '1'
--	);
--	end generate;
--	G2: for I in 0 to 7 generate
--		L2: DFlipFlop
--	port map(
--		clock => clk,
--		q => synch2(I),
--		D => synch1(I),
--		nRST => '1',
--		en => '1'
--	);	
--	end generate;
END SYN;