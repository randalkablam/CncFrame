LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

package Common is
type RateMap is array (natural range <>) of std_logic_vector(23 DOWNTO 0);
type CountMap is array (natural range <>) of std_logic_vector(23 DOWNTO 0);
type ByteArray is array(natural range <>) of std_logic_vector(7 downto 0);
type OnTypeMap is array(natural range <>) of std_logic_vector(15 downto 0);
end Common;

package body Common is

end Common;