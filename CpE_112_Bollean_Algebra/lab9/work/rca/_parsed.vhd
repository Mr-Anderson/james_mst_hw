-- file RCA.vhd
library ieee;
use ieee.std_logic_1164.all;
entity RCA is
port(a, b : in std_logic_vector(3 downto 0);
cout : out std_logic;
sum : out std_logic_vector(3 downto 0));
end entity RCA;
