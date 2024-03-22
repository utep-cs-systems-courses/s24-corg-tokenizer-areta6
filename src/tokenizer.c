//creating the c file for tokenizer

#include<stdio.h>
#include "tokenizer.h"
#include<stdlib.h>

//evaluating if char is a space ('\t' or ' ')
//checking with an if
//empty char is not printable
int space_char(char c)
{
  if (c != 0 && (c == '\t' || c == ' '))
    {
      return 1;
    }
  return 0; //had this one originally as 2 if statements but found it better to just combine them
}


// the inverse of the given requirements of the top one

int non_space_char(char c)
{
  if(c != 0 && (c != '\t' && c != ' '))
    {
      return 1;
    }
  return 0; 
}

//return a pointer to first character of the next
//return zero pointer if str does not contain any tokens.
//the next token should take place after 
char *token_start(char *str)
{
  int i = 0; // start of the token
  while(space_char(str[i]) == 1) //if we return a 1 this will lead to getting the address of the start of the next token
    {
      i++;
    }
  return &str[i];//return address 
}

// should return where a token ends
//effectively the opposite of start
char *token_terminator(char *token)
{
  int i = 0;
  while(non_space_char(i) == 1)//finding the address of the end of the token
    {
      i++;
    }
  return &token[i];
}

//count the number of tokens
int count_tokens(char *str)
{
  int tNumber = 0;
  int i = 0;
  while(str[i] != '\0') //running the string through the end
    {
      if(non_space_char(str[i+1]) && space_char(str[i]))//if its a space and the next position is not then if is true
	{
	  tNumber ++;
	}
      i++;
    }
  return tNumber;
}

//returns allcated new zero-terminated string
//conatins len chars from instr
char copy_str(char *inStr, short len)
{
  int i = 0;
  
}

char **tokenize(char* str)
{
  
}

void print_tokens(char **tokens)
{
  
}

void free_tokens(char **tokens)
{
  
}
