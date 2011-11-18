-- sram.hex 

library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use WORK.I8051_LIB.all;

entity I8051_ROM is
    port(rst      : in  STD_LOGIC;
         --clk      : in  STD_LOGIC;
         addr     : in  UNSIGNED (7 downto 0);
         data     : out UNSIGNED (7 downto 0);
         rd       : in  STD_LOGIC);
end I8051_ROM;

architecture BHV of I8051_ROM is

    type ROM_TYPE is array (0 to 22) of UNSIGNED (7 downto 0);

    constant PROGRAM : ROM_TYPE := (
    
	   
	"01110100",
    "00000011",	  
	"11111000",	  
	"01110100",	 
	"00000000", 
	"11111010",	      
	"01110100", 
	"00000100",	  
	"11000011",	    
	"00111010", 
	"11111010",	  
	"11101000",
	"11000011",
	"00110100",
	"11111111",
	"11111000",
	"01100000",
	"00000010",
	"10000000",
	"11110010",
	"11101010",
	"10000000",
	"11111101"       -- NOP   
	);	 
begin

   process(rst,addr, rd)
    begin
        if( rst = '1' ) then

            data <= "00000000";
        --elsif( clk'event and clk = '1' ) then

            elsif( rd = '0' ) then

                data <= PROGRAM(conv_integer(addr));
            
            end if;

    end process;
end BHV;