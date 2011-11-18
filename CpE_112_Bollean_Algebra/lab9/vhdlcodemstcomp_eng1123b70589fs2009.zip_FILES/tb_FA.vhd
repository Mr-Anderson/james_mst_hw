-- tb_FA.vhd : testbench
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity tb_FA is
end entity tb_FA;
architecture testbench of tb_FA is
component FA is
port(a, b, cin : in std_logic;
cout : out std_logic;
sum : out std_logic);
end component;
signal a, b, cin, sum : std_logic;
signal cout : std_logic;
begin
UUT : FA
port map(a, b, cin, cout, sum);

inputs : process
begin


a <= '0';
b <= '0';
cin <= '0';
wait for 50 ns;
a <= '0';
b <= '0';
cin <= '1';
wait for 50 ns;

a <= '0';
b <= '1';
cin <= '0';
wait for 50 ns;
a <= '0';
b <= '1';
cin <= '1';
wait for 50 ns;

a <= '1';
b <= '0';
cin <= '0';
wait for 50 ns;
a <= '1';
b <= '0';
cin <= '1';
wait for 50 ns;

a <= '1';
b <= '1';
cin <= '0';
wait for 50 ns;
a <= '1';
b <= '1';
cin <= '1';
wait for 50 ns;

wait;
end process inputs;
end architecture testbench;
configuration cfg_tb_FA of tb_FA is
for testbench
for UUT: FA
end for;
end for;
end cfg_tb_FA;
