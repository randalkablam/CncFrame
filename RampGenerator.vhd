LIBRARY ieee;
USE ieee.std_logic_1164.all;
    use ieee.numeric_std.all;

ENTITY RampGenerator IS
GENERIC (N : integer := 24);
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
END RampGenerator;

ARCHITECTURE SYN OF RampGenerator IS
signal rateDeltaSig : unsigned(N-1 downto 0) := to_unsigned(0, N);
signal rateOutputSig : unsigned(N-1 downto 0) := to_unsigned(0, N);
signal maxRampUpCountVal : unsigned(N-1 downto 0) := to_unsigned(0, N);

BEGIN
pClk : process (CLK) 
variable counter : unsigned(N-1 downto 0) := to_unsigned(0, N);
variable descend : std_logic := '0';
begin
	
	if CLK'event and CLK = '1' then
--		if((unsigned(TARG_COUNT) > unsigned(CUR_COUNT))) then
--			rateOutputSig <= unsigned(TARG_RATE);
--		else
--			rateOutputSig <= to_unsigned(0, N);
--		end if;
		if nRST = '0' then
			descend := '0';
			rateDeltaSig <= to_unsigned(0, N);
			rateOutputSig <= to_unsigned(0, N);
		elsif(counter = (unsigned(RAMP_RATE)))  then
			if (to_integer(rateOutputSig) < to_integer(unsigned(TARG_RATE))) and '0' = descend and ((unsigned(TARG_COUNT) - unsigned(CUR_COUNT)) > unsigned(maxRampUpCountVal)) then
				rateOutputSig <= unsigned(START_RATE) + rateDeltaSig;
				rateDeltaSig <= (rateDeltaSig + 1);
				maxRampUpCountVal <= unsigned(CUR_COUNT);
			elsif (not((unsigned(TARG_COUNT) - unsigned(CUR_COUNT)) > unsigned(maxRampUpCountVal)) or descend = '1')  then
				rateOutputSig <= unsigned(START_RATE) + rateDeltaSig;
				if not(rateDeltaSig = to_unsigned(0,N)) then
					rateDeltaSig <= (rateDeltaSig - 1);
				end if;
			--else
				descend := '1';
			end if;
----			
			counter := to_unsigned(0, N);
		else 
			counter := counter + 1;
		end if;
	end if;
end process;	
OUT_RATE <= std_logic_vector(rateOutputSig(N-1 downto 0));
END SYN;