-- Set up rates via programmable interface


USE work.Common.all;
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
--use IEEE.std_logic_signed.all;
--use IEEE.std_logic_unsigned.all;
use ieee.numeric_std.ALL;

--use IEEE.STD_LOGIC_ARITH.ALL;


ENTITY ConfigProcessor IS
PORT(
	MCLK : in std_logic;
	nRST : in std_logic;
	SCL  : inout std_logic;
	SDA : inout std_logic;
	START_RATES: out RateMap(9 DOWNTO 0);
	TARG_RATES: out RateMap(9 DOWNTO 0);
	TARG_RAMPS: out RateMap(9 DOWNTO 0);
	TARG_COUNTS: out CountMap(9 DOWNTO 0);
	RAMP_EN : out std_logic_vector(9 DOWNTO 0);
	STEP_DIR : out std_logic_vector(9 downto 0);
	SERVO_ON_TIME : out OnTypeMap(5 downto 0);
	SERVO_EN : out std_logic_vector(5 downto 0)

);
END ConfigProcessor;

ARCHITECTURE SYN of ConfigProcessor IS


-- COMPONENTS --
	component I2CSLAVE
		generic( DEVICE: std_logic_vector(7 downto 0));
		port(
			MCLK		: in	std_logic;
			nRST		: in	std_logic;
			SDA_IN		: in	std_logic;
			SCL_IN		: in	std_logic;
			SDA_OUT		: out	std_logic;
			SCL_OUT		: out	std_logic;
			ADDRESS		: out	std_logic_vector(7 downto 0);
			DATA_OUT	: out	std_logic_vector(7 downto 0);
			DATA_IN		: in	std_logic_vector(7 downto 0);
			WR			: out	std_logic;
			RD			: out	std_logic
		);
	end component;
	
	component sp256x8
		port(
			address		: in	std_logic_vector(7 downto 0);
			clock		: in	std_logic;
			data		: in	std_logic_vector(7 downto 0);
			wren		: in	std_logic;
			q			: out	std_logic_vector(7 downto 0)
		);
	end component;
	
	component Demux
		GENERIC(
			NUM_IN : integer := 123
		);
		PORT (
			clk : in std_logic;
			control : in unsigned;
			input : std_logic_vector(7 downto 0);
			outputs : out ByteArray(NUM_IN - 1 downto 0)
		);
	end component;
	
	-- SIGNALS --
	signal SDA_IN		: std_logic;
	signal SCL_IN		: std_logic;
	signal SDA_OUT		: std_logic;
	signal SCL_OUT		: std_logic;
	signal ADDRESS		: std_logic_vector(7 downto 0);
	signal DATA_OUT		: std_logic_vector(7 downto 0);
	signal DATA_IN		: std_logic_vector(7 downto 0);
	signal WR			: std_logic;
	signal RD			: std_logic;
	
	signal q			: std_logic_vector(7 downto 0);
	signal BUFFER8		: std_logic_vector(7 downto 0);

	signal AddrOffsetSig : unsigned(7 downto 0);
BEGIN


-- PORT MAP --
	demux1 : Demux
		port map (
			clk => MCLK,
			control => unsigned(ADDRESS),
			input => DATA_OUT,
			outputs(0) => TARG_RATES(0)(23 downto 16),
			outputs(1) => TARG_RATES(0)(15 downto 8),
			outputs(2) => TARG_RATES(0)(7 downto 0),
			outputs(3) => TARG_RATES(1)(23 downto 16),
			outputs(4) => TARG_RATES(1)(15 downto 8),
			outputs(5) => TARG_RATES(1)(7 downto 0),
			outputs(6) => TARG_RATES(2)(23 downto 16),
			outputs(7) => TARG_RATES(2)(15 downto 8),
			outputs(8) => TARG_RATES(2)(7 downto 0),
			outputs(9) => TARG_RATES(3)(23 downto 16),
			outputs(10) => TARG_RATES(3)(15 downto 8),
			outputs(11) => TARG_RATES(3)(7 downto 0),
			outputs(12) => TARG_RATES(4)(23 downto 16),
			outputs(13) => TARG_RATES(4)(15 downto 8),
			outputs(14) => TARG_RATES(4)(7 downto 0),
			outputs(15) => TARG_RATES(5)(23 downto 16),
			outputs(16) => TARG_RATES(5)(15 downto 8),
			outputs(17) => TARG_RATES(5)(7 downto 0),
			outputs(18) => TARG_RATES(6)(23 downto 16),
			outputs(19) => TARG_RATES(6)(15 downto 8),
			outputs(20) => TARG_RATES(6)(7 downto 0),
			outputs(21) => TARG_RATES(7)(23 downto 16),
			outputs(22) => TARG_RATES(7)(15 downto 8),
			outputs(23) => TARG_RATES(7)(7 downto 0),
			outputs(24) => TARG_RATES(8)(23 downto 16),
			outputs(25) => TARG_RATES(8)(15 downto 8),
			outputs(26) => TARG_RATES(8)(7 downto 0),
			outputs(27) => TARG_RATES(9)(23 downto 16),
			outputs(28) => TARG_RATES(9)(15 downto 8),
			outputs(29) => TARG_RATES(9)(7 downto 0),
			
			outputs(30) => TARG_RAMPS(0)(23 downto 16),
			outputs(31) => TARG_RAMPS(0)(15 downto 8),
			outputs(32) => TARG_RAMPS(0)(7 downto 0),
			outputs(33) => TARG_RAMPS(1)(23 downto 16),
			outputs(34) => TARG_RAMPS(1)(15 downto 8),
			outputs(35) => TARG_RAMPS(1)(7 downto 0),
			outputs(36) => TARG_RAMPS(2)(23 downto 16),
			outputs(37) => TARG_RAMPS(2)(15 downto 8),
			outputs(38) => TARG_RAMPS(2)(7 downto 0),
			outputs(39) => TARG_RAMPS(3)(23 downto 16),
			outputs(40) => TARG_RAMPS(3)(15 downto 8),
			outputs(41) => TARG_RAMPS(3)(7 downto 0),
			outputs(42) => TARG_RAMPS(4)(23 downto 16),
			outputs(43) => TARG_RAMPS(4)(15 downto 8),
			outputs(44) => TARG_RAMPS(4)(7 downto 0),
			outputs(45) => TARG_RAMPS(5)(23 downto 16),
			outputs(46) => TARG_RAMPS(5)(15 downto 8),
			outputs(47) => TARG_RAMPS(5)(7 downto 0),
			outputs(48) => TARG_RAMPS(6)(23 downto 16),
			outputs(49) => TARG_RAMPS(6)(15 downto 8),
			outputs(50) => TARG_RAMPS(6)(7 downto 0),
			outputs(51) => TARG_RAMPS(7)(23 downto 16),
			outputs(52) => TARG_RAMPS(7)(15 downto 8),
			outputs(53) => TARG_RAMPS(7)(7 downto 0),
			outputs(54) => TARG_RAMPS(8)(23 downto 16),
			outputs(55) => TARG_RAMPS(8)(15 downto 8),
			outputs(56) => TARG_RAMPS(8)(7 downto 0),
			outputs(57) => TARG_RAMPS(9)(23 downto 16),
			outputs(58) => TARG_RAMPS(9)(15 downto 8),
			outputs(59) => TARG_RAMPS(9)(7 downto 0),
			
			outputs(60) => TARG_COUNTS(0)(23 downto 16),
			outputs(61) => TARG_COUNTS(0)(15 downto 8),
			outputs(62) => TARG_COUNTS(0)(7 downto 0),
			outputs(63) => TARG_COUNTS(1)(23 downto 16),
			outputs(64) => TARG_COUNTS(1)(15 downto 8),
			outputs(65) => TARG_COUNTS(1)(7 downto 0),
			outputs(66) => TARG_COUNTS(2)(23 downto 16),
			outputs(67) => TARG_COUNTS(2)(15 downto 8),
			outputs(68) => TARG_COUNTS(2)(7 downto 0),
			outputs(69) => TARG_COUNTS(3)(23 downto 16),
			outputs(70) => TARG_COUNTS(3)(15 downto 8),
			outputs(71) => TARG_COUNTS(3)(7 downto 0),
			outputs(72) => TARG_COUNTS(4)(23 downto 16),
			outputs(73) => TARG_COUNTS(4)(15 downto 8),
			outputs(74) => TARG_COUNTS(4)(7 downto 0),
			outputs(75) => TARG_COUNTS(5)(23 downto 16),
			outputs(76) => TARG_COUNTS(5)(15 downto 8),
			outputs(77) => TARG_COUNTS(5)(7 downto 0),
			outputs(78) => TARG_COUNTS(6)(23 downto 16),
			outputs(79) => TARG_COUNTS(6)(15 downto 8),
			outputs(80) => TARG_COUNTS(6)(7 downto 0),
			outputs(81) => TARG_COUNTS(7)(23 downto 16),
			outputs(82) => TARG_COUNTS(7)(15 downto 8),
			outputs(83) => TARG_COUNTS(7)(7 downto 0),
			outputs(84) => TARG_COUNTS(8)(23 downto 16),
			outputs(85) => TARG_COUNTS(8)(15 downto 8),
			outputs(86) => TARG_COUNTS(8)(7 downto 0),
			outputs(87) => TARG_COUNTS(9)(23 downto 16),
			outputs(88) => TARG_COUNTS(9)(15 downto 8),
			outputs(89) => TARG_COUNTS(9)(7 downto 0),
			
			outputs(90) => START_RATES(0)(23 downto 16),
			outputs(91) => START_RATES(0)(15 downto 8),
			outputs(92) => START_RATES(0)(7 downto 0),
			outputs(93) => START_RATES(1)(23 downto 16),
			outputs(94) => START_RATES(1)(15 downto 8),
			outputs(95) => START_RATES(1)(7 downto 0),
			outputs(96) => START_RATES(2)(23 downto 16),
			outputs(97) => START_RATES(2)(15 downto 8),
			outputs(98) => START_RATES(2)(7 downto 0),
			outputs(99) => START_RATES(3)(23 downto 16),
			outputs(100) => START_RATES(3)(15 downto 8),
			outputs(101) => START_RATES(3)(7 downto 0),
			outputs(102) => START_RATES(4)(23 downto 16),
			outputs(103) => START_RATES(4)(15 downto 8),
			outputs(104) => START_RATES(4)(7 downto 0),
			outputs(105) => START_RATES(5)(23 downto 16),
			outputs(106) => START_RATES(5)(15 downto 8),
			outputs(107) => START_RATES(5)(7 downto 0),
			outputs(108) => START_RATES(6)(23 downto 16),
			outputs(109) => START_RATES(6)(15 downto 8),
			outputs(110) => START_RATES(6)(7 downto 0),
			outputs(111) => START_RATES(7)(23 downto 16),
			outputs(112) => START_RATES(7)(15 downto 8),
			outputs(113) => START_RATES(7)(7 downto 0),
			outputs(114) => START_RATES(8)(23 downto 16),
			outputs(115) => START_RATES(8)(15 downto 8),
			outputs(116) => START_RATES(8)(7 downto 0),
			outputs(117) => START_RATES(9)(23 downto 16),
			outputs(118) => START_RATES(9)(15 downto 8),
			outputs(119) => START_RATES(9)(7 downto 0),
			 
			outputs(120)(0) => RAMP_EN(0),
			outputs(120)(1) => RAMP_EN(1),
			outputs(120)(2) => RAMP_EN(2),
			outputs(120)(3) => RAMP_EN(3),
			outputs(120)(4) => RAMP_EN(4),
			outputs(120)(5) => RAMP_EN(5),
			outputs(120)(6) => RAMP_EN(6),
			outputs(120)(7) => RAMP_EN(7),
			outputs(121)(0) => RAMP_EN(8),
			outputs(121)(1) => RAMP_EN(9),
			
			outputs(121)(2) => STEP_DIR(0),
			outputs(121)(3) => STEP_DIR(1),
			outputs(121)(4) => STEP_DIR(2),
			outputs(121)(5) => STEP_DIR(3),
			outputs(121)(6) => STEP_DIR(4),
			outputs(121)(7) => STEP_DIR(5),
			outputs(122)(0) => STEP_DIR(6),
			outputs(122)(1) => STEP_DIR(7),
			outputs(122)(2) => STEP_DIR(8),
			outputs(122)(3) => STEP_DIR(9)
		);
	
	AddrOffsetSig <= unsigned(ADDRESS) - 123;
	-- PORT MAP --
	demux2 : Demux
		generic map (
		NUM_IN => 13
		)
		port map (
			clk => MCLK,
			control => unsigned(AddrOffsetSig),
			input => DATA_OUT,
			outputs(0) => SERVO_ON_TIME(0)(15 downto 8),
			outputs(1) => SERVO_ON_TIME(0)(7 downto 0),
			outputs(2) => SERVO_ON_TIME(1)(15 downto 8),
			outputs(3) => SERVO_ON_TIME(1)(7 downto 0),
			outputs(4) => SERVO_ON_TIME(2)(15 downto 8),
			outputs(5) => SERVO_ON_TIME(2)(7 downto 0),
			outputs(6) => SERVO_ON_TIME(3)(15 downto 8),
			outputs(7) => SERVO_ON_TIME(3)(7 downto 0),
			outputs(8) => SERVO_ON_TIME(4)(15 downto 8),
			outputs(9) => SERVO_ON_TIME(4)(7 downto 0),
			outputs(10) => SERVO_ON_TIME(5)(15 downto 8),
			outputs(11) => SERVO_ON_TIME(5)(7 downto 0),
			
			outputs(12)(0) => SERVO_EN(0),
			outputs(12)(1) => SERVO_EN(1),
			outputs(12)(2) => SERVO_EN(2),
			outputs(12)(3) => SERVO_EN(3),
			outputs(12)(4) => SERVO_EN(4),
			outputs(12)(5) => SERVO_EN(5)
		);

	I_RAM : sp256x8
		port map (
			address	=> ADDRESS,
			clock		=> MCLK,
			data		=> DATA_OUT,
			wren		=> WR,
			q			=> q
		);
	I_I2CITF : I2CSLAVE
		generic map (DEVICE => x"38")
		port map (
			MCLK		=> MCLK,
			nRST		=> nRST,
			SDA_IN		=> SDA_IN,
			SCL_IN		=> SCL_IN,
			SDA_OUT		=> SDA_OUT,
			SCL_OUT		=> SCL_OUT,
			ADDRESS		=> ADDRESS,
			DATA_OUT	=> DATA_OUT,
			DATA_IN		=> DATA_IN,
			WR			=> WR,
			RD			=> RD
		);
	
	B8 : process(MCLK,nRST)
	begin
		if (nRST = '0') then
			BUFFER8 <= (others => '0');
		elsif (MCLK'event and MCLK='1') then
			if (RD = '1') then
				BUFFER8 <= q;
			end if;
		end if;

	end process B8;
	
	DATA_IN <= BUFFER8;
	
	--  open drain PAD pull up 1.5K needed
	SCL <= 'Z' when SCL_OUT='1' else '0';
	SCL_IN <= to_UX01(SCL);
	SDA <= 'Z' when SDA_OUT='1' else '0';
	SDA_IN <= to_UX01(SDA);



END SYN;