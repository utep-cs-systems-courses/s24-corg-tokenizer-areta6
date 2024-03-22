#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Hello Welcome to my tokenizer program, please enter any string, to exit enter '0' \n>");
  char user_input_buffer[MAX];
  fgets(user_input_buffer, MAX, stdin);


  if(user_input_buffer[0]=='0')
    {
      printf("Program closing");
      return 0;
    }
}
