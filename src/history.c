#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//create a list that houses space for history
List *init_history()
{
  List *list = malloc(sizeof(List));
  return list;
}
