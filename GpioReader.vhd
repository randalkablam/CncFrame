
LIBRARY ieee;
USE ieee.std_logic_1164.all;
    use ieee.numeric_std.all;

USE work.Common.all;

ENTITY GpioReader IS
	generic(NUM_GPIO : integer := 32);
	port(			
		MCLK : in std_logic;
		nRST : in std_logic;
		SCL  : inout std_logic;
		SDA : inout std_logic;
		GPIO_VEC : in ByteArray((NUM_GPIO / 8) - 1 downto 0)
	);
END GpioReader;


ARCHITECTURE SYN OF GpioReader IS


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
	
	
BEGIN
	I_I2CITF : I2CSLAVE
		generic map (DEVICE => x"39")
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
				elsif ADDRESS = x"01" then
					BUFFER8 <= GPIO_VEC(0);
				elsif ADDRESS = x"02" then
					BUFFER8 <= x"aa";--GPIO_VEC(1);
				elsif ADDRESS = x"03" then
					BUFFER8 <= GPIO_VEC(2);
				elsif ADDRESS = x"04" then
					BUFFER8 <= GPIO_VEC(3);
				else
					BUFFER8 <= (others => '0');

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
