/***************************************************************************
 * file name   : assembler.c                                               *
 * author      : tjf & you                                                 *
 * description : This program will assemble a .ASM file into a .OBJ file   *
 *               This program will use the "asm_parser" library to achieve *
 *			     its functionality.										   * 
 *                                                                         *
 ***************************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

#define DEBUG 01

int main(int argc, char** argv) {

	char* filename = NULL ;					// name of ASM file
	char  program [ROWS][COLS] ; 			// ASM file line-by-line
	char  program_bin_str [ROWS][17] ; 		// instructions converted to a binary string
	unsigned short int program_bin [ROWS] ; // instructions in binary (HEX)


	if( argc == 1 ) {
		printf("error1: usage: ./assembler <assembly_file.asm>\n");
		return 0;
	}
	else if( argc > 2 ) {
		printf("error1: usage: ./assembler <assembly_file.asm>\n");
		return 0;
	}
	else if( argc == 2 ) {
		filename = argv[1];
    make_dp();
	}

	int ret = read_asm_file(filename, program);

	if( ret == 2 ){
    printf("error2: read_asm_file() failed\n");
    return 0;
  }

  for( int i = 0; i < ROWS; ++i )
  {
    program_bin[i] = 0;
  }

	for( int i = 0; i < ROWS; ++i ) {
		if( strlen(program[i]) == 0 ) {
      program_bin_str[i][0] = '\0';
			break;
		}
		ret = parse_instruction(program[i], program_bin_str[i]);
    if( ret != 0 ) {
      break;
    } else {
      for(int j = 0; j < 8; j++)
      {
        char temp = program_bin_str[i][j];
        program_bin_str[i][j] = program_bin_str[i][j+8];
        program_bin_str[i][j+8] = temp;
      }
      program_bin[i] = str_to_bin(program_bin_str[i]);
    }
	}

  switch( ret ) {
    case 3:
      printf("error3: parse_instruction() failed.\n");
      return 0;
    case 4: 
      printf("error4: parse_add() failed.\n");
      return 0;
    case 5: 
      printf("error5: parse_reg() failed.\n");
      return 0;
    case 6: 
      printf("error6: parse_rmul() failed.\n");
      return 0;
    case 7: 
      printf("error7: parse_sub() failed.\n");
      return 0;
    case 8: 
      printf("error8: parse_div() failed.\n");
      return 0;
    case 9: 
      printf("error9: parse_and() failed.\n");
      return 0;
    case 10: 
      printf("error10: parse_not() failed.\n");
      return 0;
    case 11: 
      printf("error11: parse_or() failed.\n");
      return 0;
    case 12: 
      printf("error12: parse_xor() failed.\n");
      return 0;
    
  }

  ret = write_obj_file(filename, program_bin);
  if( ret == 13 ) {
    printf("error13: write_obj_file() failed.\n");
      return 0;
  }
	return 0;
}
