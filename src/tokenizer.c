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
  int i;
  for(i = 0; *(str+i) != '\0'; i++)
    {
      if(non_space_char(*(str+i))) //if we return a 1 this will lead to getting the address of the start of the next token
	{
	  return str+i; //gave me potential error for using str++
	}
    }
  return str+i;//return address 
}

// should return where a token ends
//effectively the opposite of start
char *token_terminator(char *token)
{
  int i;
  for(i = 0; *(token+i) != '\0'; i++)
    {
      if(space_char(*(token+i)))
	{
	  return token+i;
	}
    }
  return token+i;
}

//count the number of tokens
int count_tokens(char *str)
{
  int tNumber = 0;
  char *pnt = token_start(str); //points to token start position
  while(*pnt != '\0') //running the string through the end
    {
      if(non_space_char(*pnt))//if its a space and the next position is not then if is true
	{
	  tNumber ++;
	}
      pnt = token_terminator(pnt);
      pnt = token_start(pnt);
    }
  return tNumber;
}

//returns allcated new zero-terminated string
//conatins len chars from instr
char *copy_str(char *inStr, short len)
{
  int i = 0;
  char *copiedString = malloc((len+1) *sizeof(char)); //copying the string given (copied over from demo code)
  for(i = 0; i < len; i++)
    {
      copiedString[i] = inStr[i];
    }
  copiedString[i]='\0'; //once it reaches the end of the copied string it will give a 0 for zero-termination
  return copiedString;
}

char **tokenize(char* str)
{
  int strLngth = count_tokens(str); //length of given str so i can use copy_str later
  char **tokens = malloc((strLngth+1) * sizeof(char*));
  int i;
  char *tp = str;
  for(i = 0; i < strLngth; i++)
    {
      tp = token_start(tp); //finding start of token
      int length = token_length(tp); //calling my created function
      tokens[i] = copy_str(tp, length); //copyiny into tokens
      tp = token_terminator(tp); // terminating and jumping to next token
    }
  tokens[i] = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] !=0; i++) //prints tokens till tokens[i] contains nothing 
    {
      printf("%s\n",tokens[i]);
    }
}

void free_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != 0; i++)
    {
      free(tokens[i]); //freeing contents in tokens[i]
    }
  free(tokens); //freeing tokens
}

// got help for this one this will be used to help build the tokenizer
int token_length(char *str)
{
  int length = 0;
  char *strt = token_start(str);
  char *end = token_terminator(strt);
  length = end - strt;
  return length;
}

//infinite loop keeps happening once recalling from history likely need to add a separate function instead of using token_length

short str_length(char *str)
{
  short length = 0;
  int i;
  for(i = 0; *(str+i) != '\0'; i++)// navigate str while adding to length
    {
      length ++;
    }
  return length;
}


