-- file RCA.vhd
library ieee;
use ieee.std_logic_1164.all;
entity RCA is
port(a, b : in std_logic_vector(3 downto 0);
cout : out std_logic;
sum : out std_logic_vector(3 downto 0));
end entity RCA;
architecture struct_RCA of RCA is
signal cin: std_logic_vector(3 downto 0);
component FA is
port(a, b : in std_logic;
cin : in std_logic;
cout : out std_logic;
sum : out std_logic);
end component;

begin
cin(0) <= '0';
FA0 : FA
port map(a(0), b(0), cin(0), cin(1), sum(0));
FA1 : FA
port map(a(1), b(1), cin(1), cin(2), sum(1));
FA2 : FA
port map(a(2), b(2), cin(2), cin(3), sum(2));
FA3 : FA
port map(a(3), b(3), cin(3), cout, sum(3));
end architecture struct_RCA;
