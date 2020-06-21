

USE work.Common.all;
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
--use IEEE.std_logic_signed.all;
--use IEEE.std_logic_unsigned.all;
use ieee.numeric_std.ALL;


entity ServoGroup is
generic(
	NUM_SERVO : integer := 6;
	N : integer := 16
);	
port (
	clk : in std_logic;
	onTimes : in OnTypeMap(NUM_SERVO - 1 downto 0);
	nRstMap : in std_logic_vector(NUM_SERVO - 1 downto 0);
	pulseOuts : out std_logic_vector(NUM_SERVO - 1 downto 0)
);
end ServoGroup;

architecture SYN of ServoGroup is 

component ServoDriver is
port(
	clk : in std_logic;
	nRST : in std_logic;
	onTime : in std_logic_vector(N-1 downto 0);
	waveOut : out std_logic
);
end component;

COMPONENT Counter
	generic(N: integer := 32);
	PORT (
		clock		: IN STD_LOGIC ;
		q			: OUT STD_LOGIC_VECTOR (N-1 DOWNTO 0);
		inc_i       : in    std_logic_vector(N-1 downto 0);
		nRST     : IN STD_LOGIC;
		en       : IN STD_LOGIC
);
END COMPONENT;


signal clock_50Hz : std_logic;
signal counter50Sig : std_logic_vector(31 downto 0);
begin


	COUNTER1: Counter
		PORT MAP (
			clock => clk,
			q => counter50Sig,
			inc_i => x"10AABC25",
			nRST => '1',
			en => '1'
		);


	G1: for I in 0 to NUM_SERVO - 1 generate
		L: ServoDriver
			PORT MAP (
			   clk => clock_50Hz,
				nRST => nRstMap(I),
			   onTime => onTimes(I),
			   waveOut => pulseOuts(I)
			);
	end generate;

	clock_50Hz <= counter50Sig(31);

end SYN;