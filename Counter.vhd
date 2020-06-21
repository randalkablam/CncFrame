
LIBRARY ieee;
USE ieee.std_logic_1164.all;
    use ieee.numeric_std.all;


ENTITY Counter IS
	generic(N: integer := 24);
	PORT
	(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC_VECTOR (N - 1 DOWNTO 0);
		inc_i       : in    std_logic_vector(N-1 downto 0);
		nRST  : IN STD_LOGIC;
		en    : in STD_LOGIC
	);
END Counter;


ARCHITECTURE SYN OF counter IS

	SIGNAL count	: unsigned (N - 1 DOWNTO 0) := to_unsigned(0, N);
   signal incr  : unsigned(N-1 downto 0) := to_unsigned(0, N);



	

BEGIN
	q    <= std_logic_vector(count(N - 1 DOWNTO 0));
   incr <= unsigned(inc_i);
	
	clk_proc : process(clock)
	begin
		if(nRST = '0') then
				count <= to_unsigned(0, N) after 10ns;
		elsif clock'event and clock = '1' and en = '1' then
	
			
			count <= count + incr after 10ns;
			
		end if;
	end process;



END SYN;

-- ============================================================
-- CNX file retrieval info
-- ============================================================
-- Retrieval info: PRIVATE: ACLR NUMERIC "0"
-- Retrieval info: PRIVATE: ALOAD NUMERIC "0"
-- Retrieval info: PRIVATE: ASET NUMERIC "0"
-- Retrieval info: PRIVATE: ASET_ALL1 NUMERIC "1"
-- Retrieval info: PRIVATE: CLK_EN NUMERIC "0"
-- Retrieval info: PRIVATE: CNT_EN NUMERIC "0"
-- Retrieval info: PRIVATE: CarryIn NUMERIC "0"
-- Retrieval info: PRIVATE: CarryOut NUMERIC "0"
-- Retrieval info: PRIVATE: Direction NUMERIC "0"
-- Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "MAX II"
-- Retrieval info: PRIVATE: ModulusCounter NUMERIC "0"
-- Retrieval info: PRIVATE: ModulusValue NUMERIC "0"
-- Retrieval info: PRIVATE: SCLR NUMERIC "0"
-- Retrieval info: PRIVATE: SLOAD NUMERIC "0"
-- Retrieval info: PRIVATE: SSET NUMERIC "0"
-- Retrieval info: PRIVATE: SSET_ALL1 NUMERIC "1"
-- Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "0"
-- Retrieval info: PRIVATE: nBit NUMERIC "24"
-- Retrieval info: PRIVATE: new_diagram STRING "1"
-- Retrieval info: LIBRARY: lpm lpm.lpm_components.all
-- Retrieval info: CONSTANT: LPM_DIRECTION STRING "UP"
-- Retrieval info: CONSTANT: LPM_PORT_UPDOWN STRING "PORT_UNUSED"
-- Retrieval info: CONSTANT: LPM_TYPE STRING "LPM_COUNTER"
-- Retrieval info: CONSTANT: LPM_WIDTH NUMERIC "24"
-- Retrieval info: USED_PORT: clock 0 0 0 0 INPUT NODEFVAL "clock"
-- Retrieval info: USED_PORT: q 0 0 24 0 OUTPUT NODEFVAL "q[23..0]"
-- Retrieval info: CONNECT: @clock 0 0 0 0 clock 0 0 0 0
-- Retrieval info: CONNECT: q 0 0 24 0 @q 0 0 24 0
-- Retrieval info: GEN_FILE: TYPE_NORMAL Counter.vhd TRUE
-- Retrieval info: GEN_FILE: TYPE_NORMAL Counter.inc FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL Counter.cmp TRUE
-- Retrieval info: GEN_FILE: TYPE_NORMAL Counter.bsf FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL Counter_inst.vhd FALSE
-- Retrieval info: LIB_FILE: lpm
