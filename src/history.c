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
  while(temp->next != 0)
    {
      temp = temp->next;
      id++;//updating id till empty list position
    }
  //allocating space for the linked list with item
  temp->next = malloc(sizeof(Item));
  temp->next->id = id; //giving the identifier value of the list
  temp->next->str = copy_str(str,str_length(str)); //giving the value of the string to temp (token length does not work here have to make new one )  
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while (temp != 0) // allowing us to traverse the list
 {
  if (temp->id == id)
    {
      return temp->str; // returns the str value that is being searched for 
    }
  temp = temp->next;
 }
  return "id does not exist"; // id was not found so it does not exist
}


void print_history(List *list)
{
  Item *temp = list->root->next; //making sure the history starts on the right node
  while(temp != 0) //traversing list like before
    {
      printf("%d: %s\n", temp->id, temp->str); //printing id and str for all nodes
      temp->next;
    }
  printf("\n");
}

void free_history(List *list)
{
  //Item *temp; likely wont need this
  Item *cur = list->root; //current list position
  while(cur->next != 0)
    {
      Item * prev = cur; //saving current position to previous "deleting node"
      cur = cur->next; //next node selected
      free(prev->str); //removing its str value
      free(prev); //free's the value of prev
    }
  free(cur->str); //catching the last node
  free(cur);
  free(list); //deleting list
  printf("History has Been Cleared. \n");
}
