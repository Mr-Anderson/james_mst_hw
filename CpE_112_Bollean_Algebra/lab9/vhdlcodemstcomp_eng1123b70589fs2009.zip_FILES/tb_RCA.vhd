-- tb_RCA.vhd : testbench
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity tb_RCA is
end entity tb_RCA;
architecture testbench of tb_RCA is
component RCA is
port(a, b : in std_logic_vector(3 downto 0);
cout : out std_logic;
sum : out std_logic_vector(3 downto 0));
end component;
signal a, b, sum : std_logic_vector(3 downto 0);
signal cout : std_logic;
signal incorrect : std_logic := '0';
signal input_vec: std_logic_vector(7 downto 0);
signal test_a, test_b, test_sum: std_logic_vector(4 downto 0);
begin
UUT : RCA
port map(a, b, cout, sum);
a <= input_vec(3 downto 0);
b <= input_vec(7 downto 4);
test_a <= '0' & input_vec(3 downto 0);
test_b <= '0' & input_vec(7 downto 4);
test_sum <= test_a + test_b;
inputs : process
begin
input_vec <= "00000000";
for i in 0 to 255 loop
wait for 50 ns;
if (cout /= test_sum(4)) or (sum /= test_sum(3 downto 0)) then
incorrect <= '1';
end if;
input_vec <= input_vec + 1;
end loop;
wait;
end process inputs;
end architecture testbench;
configuration cfg_tb_RCA of tb_RCA is
for testbench
for UUT: RCA
end for;
end for;
end cfg_tb_RCA;
