/***************************************************************
 * Name:      mcs_51_disassembly.c
 * Purpose:   实现mcs_51_disassembly接口
 * Author:    HYH (hyhsystem.cn)
 * Created:   2025-02-14
 * Copyright: HYH (hyhsystem.cn)
 * License:   MIT
 **************************************************************/
#include "mcs_51_disassembly.h"


const hs_mcs_51_disassembly_instruction_t hs_mcs_51_disassembly_instruction_table[]=
{
    { 0x00, 0xff, ' ', 1, "NOP"},
    { 0x01, 0xff, 'A', 2, "AJMP %A"},
    { 0x02, 0xff, 'L', 3, "LJMP %l"},
    { 0x03, 0xff, ' ', 1, "RR A"},
    { 0x04, 0xff, ' ', 1, "INC A"},
    { 0x05, 0xff, ' ', 2, "INC %a"},
    { 0x06, 0xff, ' ', 1, "INC @R0"},
    { 0x07, 0xff, ' ', 1, "INC @R1"},
    { 0x08, 0xff, ' ', 1, "INC R0"},
    { 0x09, 0xff, ' ', 1, "INC R1"},
    { 0x0a, 0xff, ' ', 1, "INC R2"},
    { 0x0b, 0xff, ' ', 1, "INC R3"},
    { 0x0c, 0xff, ' ', 1, "INC R4"},
    { 0x0d, 0xff, ' ', 1, "INC R5"},
    { 0x0e, 0xff, ' ', 1, "INC R6"},
    { 0x0f, 0xff, ' ', 1, "INC R7"},
    { 0x10, 0xff, 'R', 3, "JBC %b,%R"},
    { 0x11, 0xff, 'a', 2, "ACALL %A"},
    { 0x12, 0xff, 'l', 3, "LCALL %l", true},
    { 0x13, 0xff, ' ', 1, "RRC A"},
    { 0x14, 0xff, ' ', 1, "DEC A"},
    { 0x15, 0xff, ' ', 2, "DEC %a"},
    { 0x16, 0xff, ' ', 1, "DEC @R0"},
    { 0x17, 0xff, ' ', 1, "DEC @R1"},
    { 0x18, 0xff, ' ', 1, "DEC R0"},
    { 0x19, 0xff, ' ', 1, "DEC R1"},
    { 0x1a, 0xff, ' ', 1, "DEC R2"},
    { 0x1b, 0xff, ' ', 1, "DEC R3"},
    { 0x1c, 0xff, ' ', 1, "DEC R4"},
    { 0x1d, 0xff, ' ', 1, "DEC R5"},
    { 0x1e, 0xff, ' ', 1, "DEC R6"},
    { 0x1f, 0xff, ' ', 1, "DEC R7"},
    { 0x20, 0xff, 'R', 3, "JB %b,%R"},
    { 0x21, 0xff, 'A', 2, "AJMP %A"},
    { 0x22, 0xff, '_', 1, "RET"},
    { 0x23, 0xff, ' ', 1, "RL A"},
    { 0x24, 0xff, ' ', 2, "ADD A,#%d"},
    { 0x25, 0xff, ' ', 2, "ADD A,%a"},
    { 0x26, 0xff, ' ', 1, "ADD A,@R0"},
    { 0x27, 0xff, ' ', 1, "ADD A,@R1"},
    { 0x28, 0xff, ' ', 1, "ADD A,R0"},
    { 0x29, 0xff, ' ', 1, "ADD A,R1"},
    { 0x2a, 0xff, ' ', 1, "ADD A,R2"},
    { 0x2b, 0xff, ' ', 1, "ADD A,R3"},
    { 0x2c, 0xff, ' ', 1, "ADD A,R4"},
    { 0x2d, 0xff, ' ', 1, "ADD A,R5"},
    { 0x2e, 0xff, ' ', 1, "ADD A,R6"},
    { 0x2f, 0xff, ' ', 1, "ADD A,R7"},
    { 0x30, 0xff, 'R', 3, "JNB %b,%R"},
    { 0x31, 0xff, 'a', 2, "ACALL %A", true},
    { 0x32, 0xff, '_', 1, "RETI"},
    { 0x33, 0xff, ' ', 1, "RLC A"},
    { 0x34, 0xff, ' ', 2, "ADDC A,#%d"},
    { 0x35, 0xff, ' ', 2, "ADDC A,%a"},
    { 0x36, 0xff, ' ', 1, "ADDC A,@R0"},
    { 0x37, 0xff, ' ', 1, "ADDC A,@R1"},
    { 0x38, 0xff, ' ', 1, "ADDC A,R0"},
    { 0x39, 0xff, ' ', 1, "ADDC A,R1"},
    { 0x3a, 0xff, ' ', 1, "ADDC A,R2"},
    { 0x3b, 0xff, ' ', 1, "ADDC A,R3"},
    { 0x3c, 0xff, ' ', 1, "ADDC A,R4"},
    { 0x3d, 0xff, ' ', 1, "ADDC A,R5"},
    { 0x3e, 0xff, ' ', 1, "ADDC A,R6"},
    { 0x3f, 0xff, ' ', 1, "ADDC A,R7"},
    { 0x40, 0xff, 'r', 2, "JC %r"},
    { 0x41, 0xff, 'A', 2, "AJMP %A"},
    { 0x42, 0xff, ' ', 2, "ORL %a,A"},
    { 0x43, 0xff, ' ', 3, "ORL %a,#%D"},
    { 0x44, 0xff, ' ', 2, "ORL A,#%d"},
    { 0x45, 0xff, ' ', 2, "ORL A,%a"},
    { 0x46, 0xff, ' ', 1, "ORL A,@R0"},
    { 0x47, 0xff, ' ', 1, "ORL A,@R1"},
    { 0x48, 0xff, ' ', 1, "ORL A,R0"},
    { 0x49, 0xff, ' ', 1, "ORL A,R1"},
    { 0x4a, 0xff, ' ', 1, "ORL A,R2"},
    { 0x4b, 0xff, ' ', 1, "ORL A,R3"},
    { 0x4c, 0xff, ' ', 1, "ORL A,R4"},
    { 0x4d, 0xff, ' ', 1, "ORL A,R5"},
    { 0x4e, 0xff, ' ', 1, "ORL A,R6"},
    { 0x4f, 0xff, ' ', 1, "ORL A,R7"},
    { 0x50, 0xff, 'r', 2, "JNC %r"},
    { 0x51, 0xff, 'a', 2, "ACALL %A", true},
    { 0x52, 0xff, ' ', 2, "ANL %a,A"},
    { 0x53, 0xff, ' ', 3, "ANL %a,#%D"},
    { 0x54, 0xff, ' ', 2, "ANL A,#%d"},
    { 0x55, 0xff, ' ', 2, "ANL A,%a"},
    { 0x56, 0xff, ' ', 1, "ANL A,@R0"},
    { 0x57, 0xff, ' ', 1, "ANL A,@R1"},
    { 0x58, 0xff, ' ', 1, "ANL A,R0"},
    { 0x59, 0xff, ' ', 1, "ANL A,R1"},
    { 0x5a, 0xff, ' ', 1, "ANL A,R2"},
    { 0x5b, 0xff, ' ', 1, "ANL A,R3"},
    { 0x5c, 0xff, ' ', 1, "ANL A,R4"},
    { 0x5d, 0xff, ' ', 1, "ANL A,R5"},
    { 0x5e, 0xff, ' ', 1, "ANL A,R6"},
    { 0x5f, 0xff, ' ', 1, "ANL A,R7"},
    { 0x60, 0xff, 'r', 2, "JZ %r"},
    { 0x61, 0xff, 'A', 2, "AJMP %A"},
    { 0x62, 0xff, ' ', 2, "XRL %a,A"},
    { 0x63, 0xff, ' ', 3, "XRL %a,#%D"},
    { 0x64, 0xff, ' ', 2, "XRL A,#%d"},
    { 0x65, 0xff, ' ', 2, "XRL A,%a"},
    { 0x66, 0xff, ' ', 1, "XRL A,@R0"},
    { 0x67, 0xff, ' ', 1, "XRL A,@R1"},
    { 0x68, 0xff, ' ', 1, "XRL A,R0"},
    { 0x69, 0xff, ' ', 1, "XRL A,R1"},
    { 0x6a, 0xff, ' ', 1, "XRL A,R2"},
    { 0x6b, 0xff, ' ', 1, "XRL A,R3"},
    { 0x6c, 0xff, ' ', 1, "XRL A,R4"},
    { 0x6d, 0xff, ' ', 1, "XRL A,R5"},
    { 0x6e, 0xff, ' ', 1, "XRL A,R6"},
    { 0x6f, 0xff, ' ', 1, "XRL A,R7"},
    { 0x70, 0xff, 'r', 2, "JNZ %r"},
    { 0x71, 0xff, 'a', 2, "ACALL %A", true},
    { 0x72, 0xff, ' ', 2, "ORL C,%b"},
    { 0x73, 0xff, '_', 1, "JMP @A+DPTR"},
    { 0x74, 0xff, ' ', 2, "MOV A,#%d"},
    { 0x75, 0xff, ' ', 3, "MOV %a,#%D"},
    { 0x76, 0xff, ' ', 2, "MOV @R0,#%d"},
    { 0x77, 0xff, ' ', 2, "MOV @R1,#%d"},
    { 0x78, 0xff, ' ', 2, "MOV R0,#%d"},
    { 0x79, 0xff, ' ', 2, "MOV R1,#%d"},
    { 0x7a, 0xff, ' ', 2, "MOV R2,#%d"},
    { 0x7b, 0xff, ' ', 2, "MOV R3,#%d"},
    { 0x7c, 0xff, ' ', 2, "MOV R4,#%d"},
    { 0x7d, 0xff, ' ', 2, "MOV R5,#%d"},
    { 0x7e, 0xff, ' ', 2, "MOV R6,#%d"},
    { 0x7f, 0xff, ' ', 2, "MOV R7,#%d"},
    { 0x80, 0xff, 's', 2, "SJMP %r"},
    { 0x81, 0xff, 'A', 2, "AJMP %A"},
    { 0x82, 0xff, ' ', 2, "ANL C,%b"},
    { 0x83, 0xff, ' ', 1, "MOVC A,@A+PC"},
    { 0x84, 0xff, ' ', 1, "DIV AB"},
    { 0x85, 0xff, ' ', 3, "MOV %8,%a"},
    { 0x86, 0xff, ' ', 2, "MOV %a,@R0"},
    { 0x87, 0xff, ' ', 2, "MOV %a,@R1"},
    { 0x88, 0xff, ' ', 2, "MOV %a,R0"},
    { 0x89, 0xff, ' ', 2, "MOV %a,R1"},
    { 0x8a, 0xff, ' ', 2, "MOV %a,R2"},
    { 0x8b, 0xff, ' ', 2, "MOV %a,R3"},
    { 0x8c, 0xff, ' ', 2, "MOV %a,R4"},
    { 0x8d, 0xff, ' ', 2, "MOV %a,R5"},
    { 0x8e, 0xff, ' ', 2, "MOV %a,R6"},
    { 0x8f, 0xff, ' ', 2, "MOV %a,R7"},
    { 0x90, 0xff, ' ', 3, "MOV DPTR,#%6"},
    { 0x91, 0xff, 'a', 2, "ACALL %A", true},
    { 0x92, 0xff, ' ', 2, "MOV %b,C"},
    { 0x93, 0xff, ' ', 1, "MOVC A,@A+DPTR"},
    { 0x94, 0xff, ' ', 2, "SUBB A,#%d"},
    { 0x95, 0xff, ' ', 2, "SUBB A,%a"},
    { 0x96, 0xff, ' ', 1, "SUBB A,@R0"},
    { 0x97, 0xff, ' ', 1, "SUBB A,@R1"},
    { 0x98, 0xff, ' ', 1, "SUBB A,R0"},
    { 0x99, 0xff, ' ', 1, "SUBB A,R1"},
    { 0x9a, 0xff, ' ', 1, "SUBB A,R2"},
    { 0x9b, 0xff, ' ', 1, "SUBB A,R3"},
    { 0x9c, 0xff, ' ', 1, "SUBB A,R4"},
    { 0x9d, 0xff, ' ', 1, "SUBB A,R5"},
    { 0x9e, 0xff, ' ', 1, "SUBB A,R6"},
    { 0x9f, 0xff, ' ', 1, "SUBB A,R7"},
    { 0xa0, 0xff, ' ', 2, "ORL C,/%b"},
    { 0xa1, 0xff, 'A', 2, "AJMP %A"},
    { 0xa2, 0xff, ' ', 2, "MOV C,%b"},
    { 0xa3, 0xff, ' ', 1, "INC DPTR"},
    { 0xa4, 0xff, ' ', 1, "MUL AB"},
    { 0xa5, 0xff, '_', 1, "-"},
    { 0xa6, 0xff, ' ', 2, "MOV @R0,%a"},
    { 0xa7, 0xff, ' ', 2, "MOV @R1,%a"},
    { 0xa8, 0xff, ' ', 2, "MOV R0,%a"},
    { 0xa9, 0xff, ' ', 2, "MOV R1,%a"},
    { 0xaa, 0xff, ' ', 2, "MOV R2,%a"},
    { 0xab, 0xff, ' ', 2, "MOV R3,%a"},
    { 0xac, 0xff, ' ', 2, "MOV R4,%a"},
    { 0xad, 0xff, ' ', 2, "MOV R5,%a"},
    { 0xae, 0xff, ' ', 2, "MOV R6,%a"},
    { 0xaf, 0xff, ' ', 2, "MOV R7,%a"},
    { 0xb0, 0xff, ' ', 2, "ANL C,/%b"},
    { 0xb1, 0xff, 'a', 2, "ACALL %A", true},
    { 0xb2, 0xff, ' ', 2, "CPL %b"},
    { 0xb3, 0xff, ' ', 1, "CPL C"},
    { 0xb4, 0xff, 'R', 3, "CJNE A,#%d,%R"},
    { 0xb5, 0xff, 'R', 3, "CJNE A,%a,%R"},
    { 0xb6, 0xff, 'R', 3, "CJNE @R0,#%d,%R"},
    { 0xb7, 0xff, 'R', 3, "CJNE @R1,#%d,%R"},
    { 0xb8, 0xff, 'R', 3, "CJNE R0,#%d,%R"},
    { 0xb9, 0xff, 'R', 3, "CJNE R1,#%d,%R"},
    { 0xba, 0xff, 'R', 3, "CJNE R2,#%d,%R"},
    { 0xbb, 0xff, 'R', 3, "CJNE R3,#%d,%R"},
    { 0xbc, 0xff, 'R', 3, "CJNE R4,#%d,%R"},
    { 0xbd, 0xff, 'R', 3, "CJNE R5,#%d,%R"},
    { 0xbe, 0xff, 'R', 3, "CJNE R6,#%d,%R"},
    { 0xbf, 0xff, 'R', 3, "CJNE R7,#%d,%R"},
    { 0xc0, 0xff, ' ', 2, "PUSH %a"},
    { 0xc1, 0xff, 'A', 2, "AJMP %A"},
    { 0xc2, 0xff, ' ', 2, "CLR %b"},
    { 0xc3, 0xff, ' ', 1, "CLR C"},
    { 0xc4, 0xff, ' ', 1, "SWAP A"},
    { 0xc5, 0xff, ' ', 2, "XCH A,%a"},
    { 0xc6, 0xff, ' ', 1, "XCH A,@R0"},
    { 0xc7, 0xff, ' ', 1, "XCH A,@R1"},
    { 0xc8, 0xff, ' ', 1, "XCH A,R0"},
    { 0xc9, 0xff, ' ', 1, "XCH A,R1"},
    { 0xca, 0xff, ' ', 1, "XCH A,R2"},
    { 0xcb, 0xff, ' ', 1, "XCH A,R3"},
    { 0xcc, 0xff, ' ', 1, "XCH A,R4"},
    { 0xcd, 0xff, ' ', 1, "XCH A,R5"},
    { 0xce, 0xff, ' ', 1, "XCH A,R6"},
    { 0xcf, 0xff, ' ', 1, "XCH A,R7"},
    { 0xd0, 0xff, ' ', 2, "POP %a"},
    { 0xd1, 0xff, 'a', 2, "ACALL %A", true},
    { 0xd2, 0xff, ' ', 2, "SETB %b"},
    { 0xd3, 0xff, ' ', 1, "SETB C"},
    { 0xd4, 0xff, ' ', 1, "DA A"},
    { 0xd5, 0xff, 'R', 3, "DJNZ %a,%R"},
    { 0xd6, 0xff, ' ', 1, "XCHD A,@R0"},
    { 0xd7, 0xff, ' ', 1, "XCHD A,@R1"},
    { 0xd8, 0xff, 'r', 2, "DJNZ R0,%r"},
    { 0xd9, 0xff, 'r', 2, "DJNZ R1,%r"},
    { 0xda, 0xff, 'r', 2, "DJNZ R2,%r"},
    { 0xdb, 0xff, 'r', 2, "DJNZ R3,%r"},
    { 0xdc, 0xff, 'r', 2, "DJNZ R4,%r"},
    { 0xdd, 0xff, 'r', 2, "DJNZ R5,%r"},
    { 0xde, 0xff, 'r', 2, "DJNZ R6,%r"},
    { 0xdf, 0xff, 'r', 2, "DJNZ R7,%r"},
    { 0xe0, 0xff, ' ', 1, "MOVX A,@DPTR"},
    { 0xe1, 0xff, 'A', 2, "AJMP %A"},
    { 0xe2, 0xff, ' ', 1, "MOVX A,@R0"},
    { 0xe3, 0xff, ' ', 1, "MOVX A,@R1"},
    { 0xe4, 0xff, ' ', 1, "CLR A"},
    { 0xe5, 0xff, ' ', 2, "MOV A,%a"},
    { 0xe6, 0xff, ' ', 1, "MOV A,@R0"},
    { 0xe7, 0xff, ' ', 1, "MOV A,@R1"},
    { 0xe8, 0xff, ' ', 1, "MOV A,R0"},
    { 0xe9, 0xff, ' ', 1, "MOV A,R1"},
    { 0xea, 0xff, ' ', 1, "MOV A,R2"},
    { 0xeb, 0xff, ' ', 1, "MOV A,R3"},
    { 0xec, 0xff, ' ', 1, "MOV A,R4"},
    { 0xed, 0xff, ' ', 1, "MOV A,R5"},
    { 0xee, 0xff, ' ', 1, "MOV A,R6"},
    { 0xef, 0xff, ' ', 1, "MOV A,R7"},
    { 0xf0, 0xff, ' ', 1, "MOVX @DPTR,A"},
    { 0xf1, 0xff, 'a', 2, "ACALL %A", true},
    { 0xf2, 0xff, ' ', 1, "MOVX @R0,A"},
    { 0xf3, 0xff, ' ', 1, "MOVX @R1,A"},
    { 0xf4, 0xff, ' ', 1, "CPL A"},
    { 0xf5, 0xff, ' ', 2, "MOV %a,A"},
    { 0xf6, 0xff, ' ', 1, "MOV @R0,A"},
    { 0xf7, 0xff, ' ', 1, "MOV @R1,A"},
    { 0xf8, 0xff, ' ', 1, "MOV R0,A"},
    { 0xf9, 0xff, ' ', 1, "MOV R1,A"},
    { 0xfa, 0xff, ' ', 1, "MOV R2,A"},
    { 0xfb, 0xff, ' ', 1, "MOV R3,A"},
    { 0xfc, 0xff, ' ', 1, "MOV R4,A"},
    { 0xfd, 0xff, ' ', 1, "MOV R5,A"},
    { 0xfe, 0xff, ' ', 1, "MOV R6,A"},
    { 0xff, 0xff, ' ', 1, "MOV R7,A"},
    { 0, 0, 0, 0, NULL }
};

const hs_mcs_51_disassembly_instruction_t *hs_mcs_51_disassembly_instruction_table_get(const uint8_t *instruction)
{
    if(instruction!=NULL)
    {
        return &hs_mcs_51_disassembly_instruction_table[(*instruction)];
    }
    return NULL;
}

size_t  hs_mcs_51_disassembly_instruction_length(const uint8_t *instruction)
{
    if(instruction!=NULL)
    {
        return hs_mcs_51_disassembly_instruction_table[(*instruction)].length;
    }
    return 0;
}

size_t  hs_mcs_51_disassembly_code_instruction_count(const uint8_t *code,size_t length)
{
    size_t ret=0;
    if(code!=NULL && length > 0)
    {
        size_t pc=0;
        while(pc<length)
        {
            ret++;
            pc+=hs_mcs_51_disassembly_instruction_length(&code[pc]);
        }
    }
    return ret;
}

size_t  hs_mcs_51_disassembly_code_instruction_type_count(const uint8_t *code,size_t length)
{
    size_t ret=0;
    if(code!=NULL && length > 0)
    {
        size_t pc=0;
        uint8_t mask[32]= {0};
        while(pc<length)
        {
            {
                mask[code[pc]/8]|=(1ULL<<(code[pc]%8));
            }
            pc+=hs_mcs_51_disassembly_instruction_length(&code[pc]);
        }
        for(size_t i=0; i<256; i++)
        {
            if((mask[i/8] & (1ULL<<(i%8)))!=0)
            {
                ret++;
            }
        }
    }
    return ret;
}
