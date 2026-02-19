#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

extern int size; // This variable is used to store the size of the result linked list.


/* Subtraction : This function performs division of two large numbers using repeated subtraction.*/

/*This function performs subtraction of two large numbers stored as doubly linked lists.*/
int subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
  int data, borrow = 0;
  int negative = 0;

  /* Step 1: Check which number is bigger */
  int len1 = 0, len2 = 0;

  int ret = list_com(&head1, &head2);

  if (ret == FAILURE)
  {
    Dlist *t1 = tail1;
    tail1 = tail2;
    tail2 = t1;
    negative = -1;
  }
  else if (ret == 2) // If numbers are equal
  {
    dl_insert_first(headR, tailR, 0); // Insert 0 at the beginning of the result linked list
    return SUCCESS;
  }

  /* Step 2: Subtraction */
  while (tail1 != NULL || tail2 != NULL)
  {
    int d1 = 0, d2 = 0;

    /* If tail1 is not NULL, then take the data from tail1 and move tail1 to the previous node */
    if (tail1)
    {
      d1 = tail1->data;
      tail1 = tail1->prev;
    }

    /* If tail2 is not NULL, then take the data from tail2 and move tail2 to the previous node */
    if (tail2)
    {
      d2 = tail2->data;
      tail2 = tail2->prev;
    }

    data = d1 - d2 - borrow;

    /* If the data is negative, then we need to borrow from the next digit */
    if (data < 0) 
    {
      data += 10; // Add 10 to the data to make it positive
      borrow = 1; // Set borrow to 1 for the next iteration
    }
    else
    {
      borrow = 0; // Reset borrow to 0 for the next iteration
    }

    dl_insert_first(headR, tailR, data); // Insert the data at the beginning of the result linked list
  }
  remove_leading_zeroes(headR, tailR); // Remove leading zeroes from the result

  /* Step 3: If the result is negative, multiply the first digit by -1 */
  if (negative && *headR)
  {
    (*headR)->data *= negative; // Multiply the first digit of the result by -1 to make it negative
  }
  return SUCCESS; // Return success as we have successfully performed the subtraction operation
}
