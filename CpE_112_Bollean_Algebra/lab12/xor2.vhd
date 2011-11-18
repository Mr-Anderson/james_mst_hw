library ieee;
use ieee.std_logic_1164.all;
entity xor2 is
port(I0, I1 : in std_logic;
OUT0 : out std_logic);
end entity xor2;
architecture df_xor2 of xor2 is
begin
OUT0 <= I0 xor I1;
end architecture df_xor2;
