#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


//very simple ui that asks for inputs and meets requirments

int main()
{
  puts("Welcome! \n");
  List *history= init_history(); //initiallizing history
  char input[100]; //allowing an input limit for user

  while(1)
    {
      printf("--Hello again Please select one of the following options-- \n");
      printf("q: Quit Program. \n t: to input a sentence to be tokenized. \n h: this prints out history of previous user input. \n !: search for a specific value in history type s followed by a number example '!3'\n");
      printf("Please Enter your choie here: ");

      fgets(input,100,stdin);

      if(input[0] == 't')//tokenizer input
	{
	  printf("\n you selected 't' \n Please enter a sentence here:");
	  fgets(input, 100, stdin);
	  printf("passed fgets\n");
	  char **tokens = tokenize(input);
	  printf("\n");
	  printf("passed tokenize(input)\n");
	  print_tokens(tokens);
	  printf("passed print_tokens");
	  add_history(history,input); //send sentence to history
	  printf("passed add_history");
	  free_tokens(tokens); //freeing tokens as to not overload memory
	}
      else if(input[0] == 'h')//history
	{
	  printf("\n Here is previous history:");
	  print_history(history); //simply print out the history 
	}
      else if(input[0] == '!')
	{
	  printf("\n Selected option !: \n");
	  char *sHistory = get_history(history,atoi(input+1)); //getting the searched history 
	  char **tokens = tokenize(sHistory);
	  printf("History: %s\n", sHistory);
	  printf("History Tokenized:\n");
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      else if(input[0] == 'q') //quit command
	{
	  printf("\n--selected q--\n");
	  printf("Thank you\n");
	  free_history(history); //clearing history from memory
	  return 0;//close program
	}
    }
}
