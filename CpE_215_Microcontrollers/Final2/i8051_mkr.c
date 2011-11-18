/*
 * Copyright (c) 1999 Tony Givargis.  Permission to copy is granted
 * provided that this header remains intact.  This software is provided
 * with no warranties.
 *
 *  Version : 2.4
 */

/*--------------------------------------------------------------------------*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*--------------------------------------------------------------------------*/

typedef struct {

    char* name;
    int msb;
    int lsb;
    int skip;
} InsForm;

/*--------------------------------------------------------------------------*/

extern const char* RomHeader;
extern const char* RomFooter;
extern const char* InsBitTbl[];
extern const InsForm InsFormTbl[];

/*--------------------------------------------------------------------------*/

unsigned Hex2Short(const char* buf) {
    
    int i;
    
    if( sscanf(buf, "%x", &i) != 1 ) {
        
        printf("hex file error\n");
        exit(1);
    }
    return i;
}

/*--------------------------------------------------------------------------*/

int Load(char* buf, unsigned char* rom, unsigned romSize, unsigned* prgSize) {
    
    unsigned len, base, type, i;
    unsigned char checksum = 0;
    char hex[16];
    
    if( buf[0] != ':' ) {

        printf("hex file error\n");
        exit(1);
    }

    hex[0] = buf[1];
    hex[1] = buf[2];
    hex[2] = 0;
    len = Hex2Short(hex);

    hex[0] = buf[3];
    hex[1] = buf[4];
    hex[2] = buf[5];
    hex[3] = buf[6];
    hex[4] = 0;
    base = Hex2Short(hex);
    
    hex[0] = buf[7];
    hex[1] = buf[8];
    hex[2] = 0;
    if( (type = Hex2Short(hex)) == 1 ) return 1;
    
    if ( (base + len) > (*prgSize) ) {
        
        (*prgSize) = base + len + 2;
    }
    
    if( (*prgSize) >= romSize || (base + len) >= romSize ) {
        
        printf("program too large\n");
        exit(1);
    }
    
    for(i=0; i<len; i++) {
        
        hex[0] = buf[ 9 + i * 2];
        hex[1] = buf[10 + i * 2];
        rom[base + i] = (unsigned char)Hex2Short(hex);
    }
    
    for(i=0; buf[i * 2 + 1] && buf[i * 2 + 2]; i++) {
        
        hex[0] = buf[i * 2 + 1];
        hex[1] = buf[i * 2 + 2];
        checksum += (unsigned char)Hex2Short(hex);
    }

    if( checksum != 0 ) {
        
        printf("checksum failed\n");
        exit(1);
    }
    return 0;
}

/*--------------------------------------------------------------------------*/

int Match(const char* binary, int msb, int lsb, const char* bit) {

    char buf[16];
  
    strcpy(buf, &binary[7-msb]);
    buf[8-lsb] = 0;
    return strcmp(bit, buf) == 0;
}

/*--------------------------------------------------------------------------*/

char* Comment(const char* binary) {
    
    static char buf[32];
    static int skip = 0;
    int i;
    
    if( skip == 0 ) {

        for(i=0; i<111; i++) {

            if( Match(binary, InsFormTbl[i].msb, 
                      InsFormTbl[i].lsb, InsBitTbl[i]) ) {

                sprintf(buf, "\t-- %s", InsFormTbl[i].name);
                skip = InsFormTbl[i].skip;
                return buf;
            }
        }
    }
    else {

        skip--;
    }
    return "";
}

/*--------------------------------------------------------------------------*/

char* ToBinary(unsigned char b) {
    
    static char buf[9];
    int i;
    
    for(i=0; i<8; i++) {
        
        buf[i] = b & (0x80 >> i) ? '1' : '0';
    }
    buf[9] = 0;
    return buf;
}

/*--------------------------------------------------------------------------*/

void WriteVhdl(unsigned char* rom, unsigned prgSize, const char* fileName) {

    FILE* fh = fopen("i8051_rom.vhd", "w");
    char* binary;
    unsigned i;
    
    assert( fh != 0 );

    fprintf(fh, "-- %s \n\n%s", fileName, RomHeader);
    fprintf(fh, "    type ROM_TYPE is array (0 to %i)", prgSize - 1);
    fprintf(fh, " of UNSIGNED (7 downto 0);\n\n");
    fprintf(fh, "    constant PROGRAM : ROM_TYPE := (\n\n");
    for(i=0; i<prgSize-1; i++) {
        
        binary = ToBinary(rom[i]);
        fprintf(fh, "\t\"%s\",%s\n", binary, Comment(binary));
    }
    binary = ToBinary(rom[prgSize-1]);
    fprintf(fh, "\t\"%s\");%s\n%s", binary, Comment(binary), RomFooter);
}

/*--------------------------------------------------------------------------*/

int main(int argc, char* argv[]) {
    
    FILE* fh;
    char buf[256];
    unsigned char rom[4096];
    unsigned prgSize = 0;
    
    memset(rom, 0, sizeof(rom));
    if( argc != 2 || (fh = fopen(argv[1], "r")) == 0 ) {
        
        printf("file argument invalid\n");
        exit(1);
    }

    while( !feof(fh) ) {
        
        fgets(buf, sizeof(buf), fh);
        if( Load(buf, rom, sizeof(rom), &prgSize) ) break;
    }
    
    WriteVhdl(rom, prgSize, argv[1]);
    return 0;
}

/*--------------------------------------------------------------------------*/

const char* RomHeader =

"library IEEE;\n"
"use IEEE.STD_LOGIC_1164.all;\n"
"use IEEE.STD_LOGIC_ARITH.all;\n"
"use WORK.I8051_LIB.all;\n"
"\n"
"entity I8051_ROM is\n"
"    port(rst      : in  STD_LOGIC;\n"
"         clk      : in  STD_LOGIC;\n"
"         addr     : in  UNSIGNED (11 downto 0);\n"
"         data     : out UNSIGNED (7 downto 0);\n"
"         rd       : in  STD_LOGIC);\n"
"end I8051_ROM;\n"
"\n"
"architecture BHV of I8051_ROM is\n"
"\n";

/*--------------------------------------------------------------------------*/

const char* RomFooter =

"begin\n"
"\n"
"    process(rst, clk)\n"
"    begin\n"
"        if( rst = '1' ) then\n"
"\n"
"            data <= CD_8;\n"
"        elsif( clk'event and clk = '1' ) then\n"
"\n"
"            if( rd = '1' ) then\n"
"\n"
"                data <= PROGRAM(conv_integer(addr));\n"
"            else\n"
"\n"
"                data <= CD_8;\n"
"            end if;\n"
"        end if;\n"
"    end process;\n"
"end BHV;";

/*--------------------------------------------------------------------------*/

const char* InsBitTbl[] = {

    "10001",
    "00101",
    "00100101",
    "0010011",
    "00100100",
    "00111",
    "00110101",
    "0011011",
    "00110100",
    "00001",
    "01011",
    "01010101",
    "0101011",
    "01010100",
    "01010010",
    "01010011",
    "10000010",
    "10110000",
    "10110101",
    "10110100",
    "10111",
    "1011011",
    "11100100",
    "11000011",
    "11000010",
    "11110100",
    "10110011",
    "10110010",
    "11010100",
    "00010100",
    "00011",
    "00010101",
    "0001011",
    "10000100",
    "11011",
    "11010101",
    "00000100",
    "00001",
    "00000101",
    "0000011",
    "10100011",
    "00100000",
    "00010000",
    "01000000",
    "01110011",
    "00110000",
    "01010000",
    "01110000",
    "01100000",
    "00010010",
    "00000010",
    "11101",
    "11100101",
    "1110011",
    "01110100",
    "11111",
    "10101",
    "01111",
    "11110101",
    "10001",
    "10000101",
    "1000011",
    "01110101",
    "1111011",
    "1010011",
    "0111011",
    "10100010",
    "10010010",
    "10010000",
    "10010011",
    "10000011",
    "1110001",
    "11100000",
    "1111001",
    "11110000",
    "10100100",
    "00000000",
    "01001",
    "01000101",
    "0100011",
    "01000100",
    "01000010",
    "01000011",
    "01110010",
    "10100000",
    "11010000",
    "11000000",
    "00100010",
    "00110010",
    "00100011",
    "00110011",
    "00000011",
    "00010011",
    "11010011",
    "11010010",
    "10000000",
    "10011",
    "10010101",
    "1001011",
    "10010100",
    "11000100",
    "11001",
    "11000101",
    "1100011",
    "1101011",
    "01101",
    "01100101",
    "0110011",
    "01100100",
    "01100010",
    "01100011",
};

/*--------------------------------------------------------------------------*/

const InsForm InsFormTbl[] = {

    { "ACALL  ", 4, 0, 1 },
    { "ADD_1  ", 7, 3, 0 },
    { "ADD_2  ", 7, 0, 1 },
    { "ADD_3  ", 7, 1, 0 },
    { "ADD_4  ", 7, 0, 1 },
    { "ADDC_1 ", 7, 3, 0 },
    { "ADDC_2 ", 7, 0, 1 },
    { "ADDC_3 ", 7, 1, 0 },
    { "ADDC_4 ", 7, 0, 1 },
    { "AJMP   ", 4, 0, 1 },
    { "ANL_1  ", 7, 3, 0 },
    { "ANL_2  ", 7, 0, 1 },
    { "ANL_3  ", 7, 1, 0 },
    { "ANL_4  ", 7, 0, 1 },
    { "ANL_5  ", 7, 0, 1 },
    { "ANL_6  ", 7, 0, 2 },
    { "ANL_7  ", 7, 0, 1 },
    { "ANL_8  ", 7, 0, 1 },
    { "CJNE_1 ", 7, 0, 2 },
    { "CJNE_2 ", 7, 0, 2 },
    { "CJNE_3 ", 7, 3, 2 },
    { "CJNE_4 ", 7, 1, 2 },
    { "CLR_1  ", 7, 0, 0 },
    { "CLR_2  ", 7, 0, 0 },
    { "CLR_3  ", 7, 0, 1 },
    { "CPL_1  ", 7, 0, 0 },
    { "CPL_2  ", 7, 0, 0 },
    { "CPL_3  ", 7, 0, 1 },
    { "DA     ", 7, 0, 0 },
    { "DEC_1  ", 7, 0, 0 },
    { "DEC_2  ", 7, 3, 0 },
    { "DEC_3  ", 7, 0, 1 },
    { "DEC_4  ", 7, 1, 0 },
    { "DIV    ", 7, 0, 0 },
    { "DJNZ_1 ", 7, 3, 1 },
    { "DJNZ_2 ", 7, 0, 2 },
    { "INC_1  ", 7, 0, 0 },
    { "INC_2  ", 7, 3, 0 },
    { "INC_3  ", 7, 0, 1 },
    { "INC_4  ", 7, 1, 0 },
    { "INC_5  ", 7, 0, 0 },
    { "JB     ", 7, 0, 2 },
    { "JBC    ", 7, 0, 2 },
    { "JC     ", 7, 0, 1 },
    { "JMP    ", 7, 0, 0 },
    { "JNB    ", 7, 0, 2 },
    { "JNC    ", 7, 0, 1 },
    { "JNZ    ", 7, 0, 1 },
    { "JZ     ", 7, 0, 1 },
    { "LCALL  ", 7, 0, 2 },
    { "LJMP   ", 7, 0, 2 },
    { "MOV_1  ", 7, 3, 0 },
    { "MOV_2  ", 7, 0, 1 },
    { "MOV_3  ", 7, 1, 0 },
    { "MOV_4  ", 7, 0, 1 },
    { "MOV_5  ", 7, 3, 0 },
    { "MOV_6  ", 7, 3, 1 },
    { "MOV_7  ", 7, 3, 1 },
    { "MOV_8  ", 7, 0, 1 },
    { "MOV_9  ", 7, 3, 1 },
    { "MOV_10 ", 7, 0, 2 },
    { "MOV_11 ", 7, 1, 1 },
    { "MOV_12 ", 7, 0, 2 },
    { "MOV_13 ", 7, 1, 0 },
    { "MOV_14 ", 7, 1, 1 },
    { "MOV_15 ", 7, 1, 1 },
    { "MOV_16 ", 7, 0, 1 },
    { "MOV_17 ", 7, 0, 1 },
    { "MOV_18 ", 7, 0, 2 },
    { "MOVC_1 ", 7, 0, 0 },
    { "MOVC_2 ", 7, 0, 0 },
    { "MOVX_1 ", 7, 1, 0 },
    { "MOVX_2 ", 7, 0, 0 },
    { "MOVX_3 ", 7, 1, 0 },
    { "MOVX_4 ", 7, 0, 0 },
    { "MUL    ", 7, 0, 0 },
    { "NOP    ", 7, 0, 0 },
    { "ORL_1  ", 7, 3, 0 },
    { "ORL_2  ", 7, 0, 1 },
    { "ORL_3  ", 7, 1, 0 },
    { "ORL_4  ", 7, 0, 1 },
    { "ORL_5  ", 7, 0, 1 },
    { "ORL_6  ", 7, 0, 2 },
    { "ORL_7  ", 7, 0, 1 },
    { "ORL_8  ", 7, 0, 1 },
    { "POP    ", 7, 0, 1 },
    { "PUSH   ", 7, 0, 1 },
    { "RET    ", 7, 0, 0 },
    { "RETI   ", 7, 0, 0 },
    { "RL     ", 7, 0, 0 },
    { "RLC    ", 7, 0, 0 },
    { "RR     ", 7, 0, 0 },
    { "RRC    ", 7, 0, 0 },
    { "SETB_1 ", 7, 0, 0 },
    { "SETB_2 ", 7, 0, 1 },
    { "SJMP   ", 7, 0, 1 },
    { "SUBB_1 ", 7, 3, 0 },
    { "SUBB_2 ", 7, 0, 1 },
    { "SUBB_3 ", 7, 1, 0 },
    { "SUBB_4 ", 7, 0, 1 },
    { "SWAP   ", 7, 0, 0 },
    { "XCH_1  ", 7, 3, 0 },
    { "XCH_2  ", 7, 0, 1 },
    { "XCH_3  ", 7, 1, 0 },
    { "XCHD   ", 7, 1, 0 },
    { "XRL_1  ", 7, 3, 0 },
    { "XRL_2  ", 7, 0, 1 },
    { "XRL_3  ", 7, 1, 0 },
    { "XRL_4  ", 7, 0, 1 },
    { "XRL_5  ", 7, 0, 1 },
    { "XRL_6  ", 7, 0, 2 }
};
