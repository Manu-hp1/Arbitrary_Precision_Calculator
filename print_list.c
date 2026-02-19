#include "main.h"

void print_list(Dlist *head)
{
  /* Cheking the list is empty or not */
  if (head == NULL)
  {
    printf("INFO : List is empty\n");
  }
  else
  {
    printf("\033[1;97m\033[1;7;93m%-1c\033[1;92m %s \033[0m\033[1;7;93m%-1c\033[0m\033[1;97m : ", ' ', "RESULT", ' ');


    while (head)
    {
      printf("%d", head->data);

      /* Travering in forward direction */
      head = head->next;
    }
    printf("\n");
  }
}