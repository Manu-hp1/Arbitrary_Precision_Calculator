#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

/* Multiplication : This function performs multiplication of two large numbers stored as doubly linked lists.*/
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
  /* Take 2 temp pointers to traverse the input linked lists */
  Dlist *temp1 = NULL;
  Dlist *temp2 = NULL;

  /* Take 2 variables to store the result of multiplication and carry */
  Dlist *res1_head = NULL, *res1_tail = NULL;
  Dlist *res2_head = NULL, *res2_tail = NULL;
  
  /* Take a variable to count the number of digits in the second operand */
  int mul, carry;
  int count = 0;

  temp2 = tail2;

  /** INFO:
   * We will be multiplying each digit of the second operand with the first operand and storing the result in res1 and res2. 
   * We will be using count variable to keep track of the number of digits in the second operand, so that we can shift the result accordingly.
   * For example, if we have to multiply 123 and 45, then we will multiply 123 with 5 and store the result in res1, then we will multiply 123 with 4 and store the result in res2. 
   * After that we will add res1 and res2 and store the result in headR and tailR. 
   */
  while (temp2 != NULL)
  {
    // Reset temp1 with tail1 for each digit of the second operand
    temp1 = tail1;
    carry = 0;

    while (temp1 != NULL)
    {
      mul = (temp1->data * temp2->data) + carry;
      carry = mul / 10; // Calculate carry
      mul = mul % 10;   // Take 1 digit

      /** INFO:
       * For the first partial product, we will be storing the result in res1. 
       * For the second partial product, we will be storing the result in res2. 
       */
      if (count == 0)
      {
        dl_insert_first(&res1_head, &res1_tail, mul);
      }
      else
      {
        dl_insert_first(&res2_head, &res2_tail, mul);
      }
      
      temp1 = temp1->prev; // Update the temp1 to the previous node
    }

    /* If there is a carry left after multiplication, then we need to add it to the result. */
    if (carry)
    {
      if (count == 0)
      {
        dl_insert_first(&res1_head, &res1_tail, carry);
      }
      else
      {
        dl_insert_first(&res2_head, &res2_tail, carry);
      }
    }

    /* From second partial product onwards */
    if (count > 0)
    {
      /* For shifting, we need to add 0 at the end of res2 for count number of times. */
      for (int i = 0; i < count; i++)
      {
        dl_insert_last(&res2_head, &res2_tail, 0);
      }

      /** INFO:
       * After multiplication, we will have 2 partial products in res1 and res2. 
       * We need to add these 2 partial products and store the result in headR and tailR. 
       * We will be using addition function for this purpose. 
       */
      addition(&res1_head, &res1_tail, &res2_head, &res2_tail, headR, tailR);

      
      /** INFO:
       * After addition, the result will be stored in headR and tailR.
       * We need to free the memory allocated for res1 and res2 after addition, because we will be using res1 and res2 for next iteration. 
       * If we do not free the memory, then we will have memory leak. 
       */
      res1_head = NULL;
      res1_tail = NULL;
      res2_head = NULL;
      res2_tail = NULL;

      /** INFO:
       * After addition, the result will be stored in headR and tailR. 
       * So we need to update res1_head and res1_tail with headR and tailR for next iteration. 
       */
      res1_head = *headR;
      res1_tail = *tailR;

      // Reset headR and tailR
      *headR = NULL;
      *tailR = NULL;
    }

    count++;
    temp2 = temp2->prev;
  }
  /* If there is only one partial product, then we need to update headR and tailR with res1_head and res1_tail. */
  *headR = res1_head;
  *tailR = res1_tail;

  return SUCCESS; // Return success as we have successfully performed the multiplication operation
}
