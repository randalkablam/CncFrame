
USE work.Common.all;
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
--use IEEE.std_logic_signed.all;
--use IEEE.std_logic_unsigned.all;
use ieee.numeric_std.ALL;

entity ServoDriver is
generic(
N : integer := 16;
FREQ : std_logic_vector(31 downto 0) := x"00000000"
);
port(
	clk : in std_logic;
	nRST : in std_logic;
	onTime : in std_logic_vector(N-1 downto 0);
	waveOut : out std_logic
);
end ServoDriver;

architecture SYN of ServoDriver is

signal counterSig : unsigned(N-1 downto 0) := to_unsigned(0, N);
signal waveOutSig : std_logic := '0';
begin



	pClk : process(clk, nRST)

	begin
		if(nRST = '0') then
			counterSig <= (others =>'0');
			waveOutSig <= '0';
		elsif(clk = '1' and clk'event) then
			counterSig <= counterSig + 1;
			if(counterSig = unsigned(onTime)) then
				waveOutSig <= '0';
			elsif (counterSig = to_unsigned(0, N)) then
				waveOutSig <= '1';
			end if;
		end if;
		
	end process;
	
	waveOut <= waveOutSig;


end SYN;