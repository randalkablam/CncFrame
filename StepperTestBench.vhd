LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.Common.all;

ENTITY StepperTestBench IS
	GENERIC(N: integer := 24);
end StepperTestBench;

ARCHITECTURE behavior OF StepperTestBench IS

	signal pulsesSig : std_logic_vector(9 DOWNTO 0) := (others => '0');
	signal clockSig : std_logic := '0';
	signal dinSig : std_logic := '0';
	signal dclkSig : std_logic := '0';
	signal addrSig : std_logic_vector(3 downto 0) := (others => '0');
	signal rstSig  : std_logic := '0';
	signal counterSig : std_logic_vector(23 downto 0) := (others => '0');
	
	
		
SIGNAL startRateMapSig : RateMap(9 DOWNTO 0);
SIGNAL targRateMapSig : RateMap(9 DOWNTO 0);
SIGNAL rampRateMapSig : RateMap(9 DOWNTO 0);
SIGNAL targCountMapSig : CountMap(9 DOWNTO 0);
SIGNAL rampEnMapSig : std_logic_vector(9 DOWNTO 0);
	
	
	COMPONENT StepperGroup
	PORT(
			clock    : in  STD_LOGIC;
			pulses	: out STD_LOGIC_VECTOR (9 DOWNTO 0);
			startRateMap : in RateMap(9 DOWNTO 0);
			targRateMap : in RateMap(9 DOWNTO 0);
			rampRateMap : in RateMap(9 DOWNTO 0);
			targCountMap : in CountMap(9 DOWNTO 0);
			rampEnMap : in std_logic_vector(9 DOWNTO 0)

	);
	END COMPONENT;
	
	COMPONENT MaxStepperDriver
		PORT(			
		   clock    : in std_logic;
			pul		: OUT STD_LOGIC ;
			RAMP_RATE : in std_logic_vector(N - 1 downto 0);
			START_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_COUNT : in std_logic_vector(N - 1 downto 0)
		);
	END COMPONENT;

	
	BEGIN
--		stepgrp : StepperGroup
--			PORT MAP (
--				clock => clockSig,
--				pulses => open,
--				rst => rstSig,
--				din => dinSig,
--				dclk => dclkSig,
--				ADDR => addrSig
--			);



		StepperGroup1 : StepperGroup
	port map(
		clock => clockSig,
		pulses => pulsesSig(9 downto 0),
		startRateMap => startRateMapSig,
		targRateMap => targRateMapSig,
		rampRateMap => rampRateMapSig,
		targCountMap => targCountMapSig,
		rampEnMap => rampEnMapSig
	);


				targRateMapSig(0) <= "000101010101010101010101";
				startRateMapSig(0) <= "000000000000000000000000";
				rampRateMapSig(0) <= "000000000000100000000000";
				targCountMapSig(0) <= "100000100000000000000000";
			
	
				targRateMapSig(1) <= "000001010101010101010101";
				startRateMapSig(1) <= "000000000000000000000000";
				rampRateMapSig(1) <= "000000000000100000000000";
				targCountMapSig(1) <= "100000100000000000000000";
			

				targRateMapSig(2) <= "000000010101010101010101";
				startRateMapSig(2) <= "000000000000000000000000";
				rampRateMapSig(2) <= "000000000000100000000000";
				targCountMapSig(2) <= "100000100000000000000000";
			
		
				targRateMapSig(3) <= "000000000101010101010101";
				startRateMapSig(3) <= "000000000000000000000000";
				rampRateMapSig(3) <= "000000000000100000000000";
				targCountMapSig(3) <= "100000100000000000000000";
			
	
				targRateMapSig(4) <= "000000000001010101010101";
				startRateMapSig(4) <= "000000000000000000000000";
				rampRateMapSig(4) <= "000000000000100000000000";
				targCountMapSig(4) <= "100000100000000000000000";
			
		
				targRateMapSig(5) <= "000000000000010101010101";
				startRateMapSig(5) <= "000000000000000000000000";
				rampRateMapSig(5) <= "000000000000100000000000";
				targCountMapSig(5) <= "100000100000000000000000";
			
				targRateMapSig(6) <= "000000000000000101010101";
				startRateMapSig(6) <= "000000000000000000000000";
				rampRateMapSig(6) <= "000000000000100000000000";
				targCountMapSig(6) <= "100000100000000000000000";
			

				targRateMapSig(7) <= "000000000000000001010101";
				startRateMapSig(7) <= "000000000000000000000000";
				rampRateMapSig(7) <= "000000000000100000000000";
				targCountMapSig(7) <= "100000100000000000000000";
			

				targRateMapSig(8) <= "000000000000000000010101";
				startRateMapSig(8) <= "000000000000000000000000";
				rampRateMapSig(8) <= "000000000000100000000000";
				targCountMapSig(8) <= "100000100000000000000000";
			

				targRateMapSig(9) <= "000000000000000000000101";
				startRateMapSig(9) <= "000000000000000000000000";
				rampRateMapSig(9) <= "000000000000100000000000";
				targCountMapSig(9) <= "100000100000000000000000";
			
		clockSig <= not clockSig after 5ns;
		
--		clk_proc: process
--		begin
--			clockSig <= '0';
--			wait for 5us;
--			clockSig <= '1';
--			wait for 5us;
--		end process;
		
		
	
	END;
	
