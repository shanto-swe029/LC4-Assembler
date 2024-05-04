/***************************************************************************
 * file name   : asm_parser.c                                              *
 * author      : shanto                                                    *
 * description : the functions are declared in asm_parser.h                *
 *               The intention of this library is to parse a .ASM file     *
 *			        										               * 
 *                                                                         *
 ***************************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

// GLobal variable for parsing oppcode and registers
char* token;
char* Rd;
char* Rs;
char* Rt;

unsigned short int dp[16];

void make_dp(){
  for( int i = 15; i >= 0; i-- )
  {
    dp[i] = (unsigned short int)(1<<(15-i));
  }
}

unsigned short int str_to_bin (char* instr_bin_str)
{
  unsigned short int binEquiv = 0;
  for( int i = 0; i < 17; ++i ) {
    if( instr_bin_str[i] == '1' )
    {
      binEquiv += dp[i];
    }
  }
  return binEquiv;
}


int parse_reg(char reg_num, char* instr_bin_str)
{
  int sz = strlen(instr_bin_str);
  
  switch( reg_num )
  {
    case '0': 
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '1': 
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '2': 
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '3': 
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '4': 
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '5': 
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '6': 
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '0'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    case '7': 
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '1'; sz++;
      instr_bin_str[sz] = '\0';
      break;
    default:
      return 5;
  }
  return 0;
  return 5;
}

char getRegNum( char* reg )
{
  char reg_num = '9'; // invalid register 
  for( int i = 0; i < strlen(reg); ++i )
  {
    if( reg[i] == ' ' ) continue;
    if( reg[i] == 'R' || reg[i] == 'r' )
    {
      return reg_num = reg[i+1];
    }
  }
  return reg_num;
}

// all helper functions 
int parse_add(char* instr, char* instr_bin_str )
{
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '0';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 4;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '0';
    instr_bin_str[12] = '0';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 4;
  }
  return ret; // expected ret = 0
  return 4;
}

int parse_mul(char* instr, char* instr_bin_str )
{
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '0';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 6;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '0';
    instr_bin_str[12] = '1';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 6;
  }
  return ret; // expected ret = 0
  return 6;
}

int parse_sub(char* instr, char* instr_bin_str ){
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '0';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 7;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '1';
    instr_bin_str[12] = '0';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 7;
  }
  return ret; // expected ret = 0
  return 7;
}
int parse_div(char* instr, char* instr_bin_str ){
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '0';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 8;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '1';
    instr_bin_str[12] = '1';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 8;
  }
  return ret; // expected ret = 0
  return 8;
}
int parse_and(char* instr, char* instr_bin_str ){
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '1';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 9;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '0';
    instr_bin_str[12] = '0';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 9;
  }
  return ret; // expected ret = 0
  return 9;
}
int parse_not(char* instr, char* instr_bin_str ){
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '1';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 10;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '0';
    instr_bin_str[12] = '1';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 10;
  }
  return ret; // expected ret = 0
  return 10;
}
int parse_or(char* instr, char* instr_bin_str ){
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '1';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 11;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '1';
    instr_bin_str[12] = '0';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 11;
  }
  return ret; // expected ret = 0
  return 11;
}
int parse_xor(char* instr, char* instr_bin_str ){
  Rd = strtok(NULL, ",");
  Rs = strtok(NULL, ",");
  Rt = strtok(NULL, ",");
  instr_bin_str[0] = '0';
  instr_bin_str[1] = '1';
  instr_bin_str[2] = '0';
  instr_bin_str[3] = '1';
  instr_bin_str[4] = '\0';
  // fetch register no 
  int ret = parse_reg(getRegNum(Rd), instr_bin_str);
  if( ret == 0 ) {
    ret = parse_reg(getRegNum(Rs), instr_bin_str);
  } else {
    return 12;
  }
  if( ret == 0 ) {
    instr_bin_str[10] = '0';
    instr_bin_str[11] = '1';
    instr_bin_str[12] = '1';
    instr_bin_str[13] = '\0';
    ret = parse_reg(getRegNum(Rt), instr_bin_str);
  } else {
    return 12;
  }
  return ret; // expected ret = 0
  return 12;
}

// Main Parser Function 
int parse_instruction(char* instr, char* instr_bin_str)
{
  token = strtok(instr, " ");

  if (strcmp(token, "ADD") == 0) 
  {
    return parse_add(instr, instr_bin_str); 
  } 
  else if (strcmp(token, "SUB") == 0) 
  {
    return parse_sub(instr, instr_bin_str); 
  } 
  else if (strcmp(token, "MUL") == 0) 
  {
    return parse_mul(instr, instr_bin_str); 
  } 
  else if (strcmp(token, "DIV") == 0) 
  {
    return parse_div(instr, instr_bin_str); 
  } 
  else if (strcmp(token, "AND") == 0) 
  {
    return parse_and(instr, instr_bin_str); 
  } 
  else if (strcmp(token, "OR") == 0) 
  {
    return parse_or(instr, instr_bin_str); 
  } 
  else if (strcmp(token, "XOR") == 0) 
  {
    return parse_xor(instr, instr_bin_str); 
  }
  else if (strcmp(token, "NOT") == 0) 
  {
    return parse_not(instr, instr_bin_str); 
  } 
  else 
  {
    return 3;
  }

  return 0;
  return 3;
}


int read_asm_file(char* filename, char program [ROWS][COLS]) 
{
  FILE * file;
  file = fopen(filename, "r");
  if( file == NULL ){
    return 2;
  }
  char currLine[COLS];
  int lineNo = 0;
  int i;
  while( fgets(currLine, COLS, file) != NULL ) {
    int sz = strlen(currLine);
    for( i = 0; i < sz; ++i ) {
      program[lineNo][i] = currLine[i];
    }
    if(program[lineNo][i-1] == '\n') {
      program[lineNo][i-1] = '\0';
    } else {
      program[lineNo][i] = '\0';
    }
    lineNo++;
  }
  program[lineNo][0] = '\0';
  fclose(file);
  return 0;
  return 2;
}


int write_obj_file(char* filename, unsigned short int program_bin[ROWS] )
{
  char* objFileName = filename;
  int sz = strlen(objFileName);
  objFileName[sz-3] = 'o';
  objFileName[sz-2] = 'b';
  objFileName[sz-1] = 'j';

  unsigned short int header =  0xDECA;
  unsigned short int location = 0x0000;
  unsigned short int numInstr = 0;

  for(int i = 0; ; ++i) {
    if(program_bin[i] == 0 )
    {
      numInstr = i;
      break;
    }
  }

  unsigned short int mmemb = numInstr;

  numInstr = (numInstr >> 8) | (numInstr << 8);

  FILE* file = fopen(objFileName, "wb");

  if( file == NULL ) return 13;
  int ret = 0;
  ret = fwrite(&header, sizeof(unsigned short int), 1, file);
  if( ret != 1 ) return 13;
  ret = fwrite(&location, sizeof(unsigned short int), 1, file);
  if( ret != 1 ) return 13;
  ret = fwrite(&numInstr, sizeof(unsigned short int), 1, file);
  if( ret != 1 ) return 13;
  ret = fwrite(program_bin, sizeof(unsigned short int), mmemb, file);
  if( ret != mmemb ) return 13;

  fclose(file);
  return 0;
}

