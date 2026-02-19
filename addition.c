#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

/* Addition : This function performs addition of two large numbers stored as doubly linked lists */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
  /* Take 2 temp pointers to traverse the input linked lists */
  Dlist *temp1, *temp2;
  temp1 = *tail1;
  temp2 = *tail2;
  int carry = 0;

  /* Traverse both linked lists until both temp1 and temp2 reaches NULL */
  while (temp1 != NULL || temp2 != NULL)
  {
    int data = 0;
    /* If both temp1 and temp2 are not NULL, then we need to add the data of both temp1 and temp2 along with the carry */
    if (temp1 != NULL && temp2 != NULL) // 10 + 10
    {
      data = temp1->data + temp2->data + carry;
    }
    /* If one of the temp1 or temp2 is NULL, then we need to add the data of the non-NULL temp along with the carry */
    else if (temp1 != NULL && temp2 == NULL) // 10 + 2
    {
      data = temp1->data + carry;
    }
    /* If temp1 is NULL and temp2 is not NULL, then we need to add the data of temp2 along with the carry */
    else if (temp1 == NULL && temp2 != NULL) // 2 + 10
    {
      data = temp2->data + carry;
    }

    carry = 0; // Reset carry to 0 for the next iteration

    /* If the data is greater than 9, then we need to carry 1 to the next digit */
    if (data > 9)
    {
      dl_insert_first(headR, tailR, data % 10); // Insert the last digit of the data at the beginning of the result linked list
      carry = 1; // Set carry to 1 for the next iteration
    }
    else
    {
      dl_insert_first(headR, tailR, data); // Insert the data at the beginning of the result linked list
    }

    /* Move temp1 and temp2 to the previous node */
    if (temp1 != NULL)
    {
      temp1 = temp1->prev;
    }
    if (temp2 != NULL)
    {
      temp2 = temp2->prev;
    }
  }

  /* If there is a carry left, then we need to insert it at the beginning of the result linked list */
  if (carry == 1)
  {
    dl_insert_first(headR, tailR, carry); // Insert the carry at the beginning of the result linked list
  }
  return SUCCESS; // Return success as we have successfully performed the addition operation
}