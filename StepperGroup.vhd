LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE work.Common.all;

-- Stepper Driver should take a input counter vector and only pulse when it is equal to the rate divider
ENTITY StepperGroup IS
	GENERIC(N: integer := 24);
	PORT
	(
			clock    : in  STD_LOGIC;
			pulses	: out STD_LOGIC_VECTOR (9 DOWNTO 0);
			startRateMap : in RateMap(9 DOWNTO 0);
			targRateMap : in RateMap(9 DOWNTO 0);
			rampRateMap : in RateMap(9 DOWNTO 0);
			targCountMap : in CountMap(9 DOWNTO 0);
			rampEnMap : in std_logic_vector(9 DOWNTO 0)
			
	);
END StepperGroup;


ARCHITECTURE SYN OF StepperGroup IS


	COMPONENT MaxStepperDriver
	PORT (
			clock    : in std_logic;
			nRST : in std_logic;
			pul		: OUT STD_LOGIC ;
			RAMP_RATE : in std_logic_vector(N - 1 downto 0);
			START_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_RATE : in std_logic_vector(N - 1 downto 0);
			TARG_COUNT : in std_logic_vector(N - 1 downto 0)
	);
	END COMPONENT;

	

	


BEGIN



	G1: for I in 0 to 9 generate
		L: MaxStepperDriver
			PORT MAP (
			   clock => clock,
				nRST => rampEnMap(I),
				pul => pulses(I),
				RAMP_RATE => rampRateMap(I),
			   START_RATE => startRateMap(I),
			   TARG_RATE => targRateMap(I),
			   TARG_COUNT => targCountMap(I)
			);
	end generate;
	
	


END SYN;