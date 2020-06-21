
LIBRARY ieee;
USE ieee.std_logic_1164.all;
    use ieee.numeric_std.all;


ENTITY DFlipFlop IS
	PORT
	(
		clock		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC;
		D       : in    STD_LOGIC;
		nRST  : IN STD_LOGIC;
		en    : IN STD_LOGIC
	);
END DFlipFlop;


ARCHITECTURE SYN OF DFlipFlop IS




	

BEGIN
	
	clk_proc : process(clock, nRST)
	begin
		if clock'event and clock = '1' and en = '1' then
			if(nRST = '0') then
				q <= '0';
			else
				q <= D;
			end if;
			
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
