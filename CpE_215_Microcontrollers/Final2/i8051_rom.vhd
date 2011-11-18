-- fix1.hex 

library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use WORK.I8051_LIB.all;

entity I8051_ROM is
    port(rst      : in  STD_LOGIC;
         clk      : in  STD_LOGIC;
         addr     : in  UNSIGNED (11 downto 0);
         data     : out UNSIGNED (7 downto 0);
         rd       : in  STD_LOGIC);
end I8051_ROM;

architecture BHV of I8051_ROM is

    type ROM_TYPE is array (0 to 248) of UNSIGNED (7 downto 0);

    constant PROGRAM : ROM_TYPE := (

	"00000010",	-- LJMP   
	"00000000",
	"11010010",
	"11000010",	-- CLR_3  
	"10010000",
	"11010010",	-- SETB_2 
	"10010001",
	"01111111",	-- MOV_7  
	"00100000",
	"01111110",	-- MOV_7  
	"01001110",
	"01111101",	-- MOV_7  
	"00000000",
	"01111100",	-- MOV_7  
	"00000000",
	"10001111",	-- MOV_9  
	"00001100",
	"10001110",	-- MOV_9  
	"00001011",
	"10001101",	-- MOV_9  
	"00001010",
	"10001100",	-- MOV_9  
	"00001001",
	"11100100",	-- CLR_1  
	"11110101",	-- MOV_8  
	"00010000",
	"11110101",	-- MOV_8  
	"00001111",
	"11110101",	-- MOV_8  
	"00001110",
	"11110101",	-- MOV_8  
	"00001101",
	"10101111",	-- MOV_6  
	"00001100",
	"10101110",	-- MOV_6  
	"00001011",
	"10101101",	-- MOV_6  
	"00001010",
	"10101100",	-- MOV_6  
	"00001001",
	"10101011",	-- MOV_6  
	"00010000",
	"10101010",	-- MOV_6  
	"00001111",
	"10101001",	-- MOV_6  
	"00001110",
	"10101000",	-- MOV_6  
	"00001101",
	"11000011",	-- CLR_2  
	"00010010",	-- LCALL  
	"00000000",
	"10001100",
	"01010000",	-- JNC    
	"00011011",
	"11100100",	-- CLR_1  
	"11111010",	-- MOV_5  
	"11111001",	-- MOV_5  
	"11111000",	-- MOV_5  
	"11100101",	-- MOV_2  
	"00010000",
	"00100100",	-- ADD_4  
	"00000001",
	"11110101",	-- MOV_8  
	"00010000",
	"11101010",	-- MOV_1  
	"00110101",	-- ADDC_2 
	"00001111",
	"11110101",	-- MOV_8  
	"00001111",
	"11101001",	-- MOV_1  
	"00110101",	-- ADDC_2 
	"00001110",
	"11110101",	-- MOV_8  
	"00001110",
	"11101000",	-- MOV_1  
	"00110101",	-- ADDC_2 
	"00001101",
	"11110101",	-- MOV_8  
	"00001101",
	"10000000",	-- SJMP   
	"11001111",
	"00100010",	-- RET    
	"00010010",	-- LCALL  
	"00000000",
	"10100010",
	"01111111",	-- MOV_7  
	"11000000",
	"00010010",	-- LCALL  
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"01001010",
	"00010010",	-- LCALL  
	"00000000",
	"11000010",
	"01111111",	-- MOV_7  
	"10000001",
	"00010010",	-- LCALL  
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"01100001",
	"00010010",	-- LCALL  
	"00000000",
	"11000010",
	"01111111",	-- MOV_7  
	"10000100",
	"00010010",	-- LCALL  
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"01101101",
	"00010010",	-- LCALL  
	"00000000",
	"11000010",
	"01111111",	-- MOV_7  
	"11000011",
	"00010010",	-- LCALL  
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"01100101",
	"00010010",	-- LCALL  
	"00000000",
	"11000010",
	"01111111",	-- MOV_7  
	"00011100",
	"00010010",	-- LCALL  
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"00011100",
	"00010010",	-- LCALL  
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"00011100",
	"00000010",	-- LJMP   
	"00000000",
	"10110010",
	"11101011",	-- MOV_1  
	"10011111",	-- SUBB_1 
	"11110101",	-- MOV_8  
	"11110000",
	"11101010",	-- MOV_1  
	"10011110",	-- SUBB_1 
	"01000010",	-- ORL_5  
	"11110000",
	"11101001",	-- MOV_1  
	"10011101",	-- SUBB_1 
	"01000010",	-- ORL_5  
	"11110000",
	"11101100",	-- MOV_1  
	"01100100",	-- XRL_4  
	"10000000",
	"11001000",	-- XCH_1  
	"01100100",	-- XRL_4  
	"10000000",
	"10011000",	-- SUBB_1 
	"01000101",	-- ORL_2  
	"11110000",
	"00100010",	-- RET    
	"11010010",	-- SETB_2 
	"10010011",
	"11000010",	-- CLR_3  
	"10010100",
	"00010010",	-- LCALL  
	"00000000",
	"11011110",
	"00010010",	-- LCALL  
	"00000000",
	"11100011",
	"00010010",	-- LCALL  
	"00000000",
	"11101000",
	"00000010",	-- LJMP   
	"00000000",
	"11101101",
	"10001111",	-- MOV_9  
	"00001000",
	"11000010",	-- CLR_3  
	"10010010",
	"00010010",	-- LCALL  
	"00000000",
	"00000011",
	"10000101",	-- MOV_10 
	"00001000",
	"10000000",
	"00010010",	-- LCALL  
	"00000000",
	"00000111",
	"11000010",	-- CLR_3  
	"10010001",
	"00100010",	-- RET    
	"10001111",	-- MOV_9  
	"00001000",
	"11010010",	-- SETB_2 
	"10010010",
	"00010010",	-- LCALL  
	"00000000",
	"00000011",
	"10000101",	-- MOV_10 
	"00001000",
	"10000000",
	"00010010",	-- LCALL  
	"00000000",
	"00000111",
	"11000010",	-- CLR_3  
	"10010001",
	"00100010",	-- RET    
	"01111000",	-- MOV_7  
	"01111111",
	"11100100",	-- CLR_1  
	"11110110",	-- MOV_13 
	"11011000",	-- DJNZ_1 
	"11111101",
	"01110101",	-- MOV_12 
	"10000001",
	"00010000",
	"00000010",	-- LJMP   
	"00000000",
	"01010010",
	"01111111",	-- MOV_7  
	"00000001",
	"00000010",	-- LJMP   
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"00000110",
	"00000010",	-- LJMP   
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"00111000",
	"00000010",	-- LJMP   
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"00001111",
	"00000010",	-- LJMP   
	"00000000",
	"10110010",
	"01111111",	-- MOV_7  
	"11000000",
	"00000010",	-- LJMP   
	"00000000",
	"10110010",
	"00000000",	-- NOP    
	"00000000");	-- NOP    
begin

    process(rst, clk)
    begin
        if( rst = '1' ) then

            data <= CD_8;
        elsif( clk'event and clk = '1' ) then

            if( rd = '1' ) then

                data <= PROGRAM(conv_integer(addr));
            else

                data <= CD_8;
            end if;
        end if;
    end process;
end BHV;