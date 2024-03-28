#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//create a list that houses space for history along with given root
List *init_history()
{
  List *list = malloc(sizeof(List));
  list -> root = malloc(sizeof(Item));
  return list;
}

// this will add a history item to the linked list
void add_history(List *list, char *str)
{
  int id = 1; //used to find the position of the item in the list 
  Item *temp = list->root;
  while(temp)
    {
      temp = temp->next;
      id++;//updating id till empty list position
    }
  //allocating space for the linked list with item
  temp->next = malloc(sizeof(Item));
  temp->id = id; //giving the identifier value of the list
  temp->str = str; //giving the value of the string to temp  
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  if(!list) //if there is no list found then id cannot be found
    {
      return "list does not exist";
    }
  else
    {
      while (temp != 0) // allowing us to traverse the list
	{
	  if (temp->id == id)
	    {
	      return temp->str; // returns the str value that is being searched for 
	    }
	  temp = temp->next;
	}
    }
  return "id does not exist"; // id was not found so it does not exist
}


void print_history(List *list)
{
  if(!list)
    {
      printf("The History is Currently Empty. \n"); //checking if history is empty
    }
  else
    {
      Item *temp = list->root->next; //making sure the history starts on the right node
      while(temp != 0) //traversing list like before
	{
	  printf("%d: %s\n", temp->id, temp->str); //printing id and str for all nodes
	  temp->next;
	}
      printf("\n");
    }
}

void free_history(List *list)
{
  Item *temp;
  Item *head = list->root; //getting the head of the list as the root where then it will be traversed through 
  while(head)
    {
      temp = head;
      head = head->next;
      free(temp); //free's the value of temp
    }
  printf("History has Been Cleared. \n");
}
