#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

/* Division : This function performs division of two large numbers represented as doubly linked lists. */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
  /* Take 2 temp pointers to hold the current portion of the dividend and the result of multiplication. */
  Dlist *curr_head = NULL, *curr_tail = NULL;

  /* If the second operand is 0, then we cannot perform division, so we return failure. */
  if (*head2 == NULL || ((*head2)->data == 0 && (*head2)->next == NULL))
  {
    return FAILURE;
  }

  /* If the first operand is less than the second operand, then the quotient is 0. */
  if (list_com(head1, head2) == FAILURE)
  {
    dl_insert_last(headR, tailR, 0);
    return SUCCESS;
  }

  Dlist *temp = *head1; // temp pointer to traverse the dividend linked list.

  /* Bring down digits from dividend until we have a number >= divisor */
  while (temp)
  {
    /* Bring next digit into current */

    /* Insert the digit at the end of the current portion. */
    dl_insert_last(&curr_head, &curr_tail, temp->data);

    /* Remove leading zeroes from the current portion. */
    remove_leading_zeroes(&curr_head, &curr_tail);

    int digit = 0; // This will hold the quotient digit for the current portion.

    /** INFO:
     * For each digit d from 9 to 0, we will multiply the divisor by d and compare it with the current portion.
     * If the product is less than or equal to the current portion, then we have found our quotient digit.
     */
    for (int d = 9; d >= 0; d--) // Loop to find the quotient digit for the current portion 0 to 9.
    {
      Dlist *mul_head = NULL, *mul_tail = NULL; // 2 temp pointers to hold the result of multiplication.
      Dlist *temp2 = *tail2;                    // temp2 pointer to traverse the divisor linked list from the end.
      int carry = 0;

      /* We will multiply each digit of the divisor with d and add the carry from the previous multiplication. */
      while (temp2)
      {
        int val = temp2->data * d + carry;               // val will hold the result of multiplication of the current digit with d and the carry from the previous multiplication.
        carry = val / 10;                                // Update carry for the next iteration.
        dl_insert_first(&mul_head, &mul_tail, val % 10); // Insert the last digit of val at the beginning of the mul linked list.
        temp2 = temp2->prev;                             // Move to the previous digit of the divisor.
      }

      /* If there is a carry left after the last multiplication, we need to insert it at the beginning of the mul linked list. */
      if (carry)
      {
        dl_insert_first(&mul_head, &mul_tail, carry); // Insert the carry at the beginning of the mul linked list.
      }

      /* If mul_result is less than or equal to current, then we have found our quotient digit for the current portion. */
      if (list_com(&curr_head, &mul_head) != FAILURE)
      {
        digit = d; // We have found our quotient digit for the current portion.

        Dlist *new_head = NULL, *new_tail = NULL; // 2 temp pointers to hold the result of subtraction.
        /** OPERATION: curr = curr - mul */
        subtraction(curr_head, curr_tail, mul_head, mul_tail, &new_head, &new_tail); // Subtract the product from the current portion to get the new current portion for the next iteration.

        
        dl_delete_list(&curr_head, &curr_tail); // Delete the old current portion linked list.
        curr_head = new_head; // Update the current portion linked list to the new current portion.
        curr_tail = new_tail; // Update the current portion linked list to the new current portion.

        dl_delete_list(&mul_head, &mul_tail); // Delete the mul linked list as we no longer need it.
        break; // Break the loop as we have found our quotient digit for the current portion.
      }

      dl_delete_list(&mul_head, &mul_tail); // Delete the mul linked list as we no longer need it.
    }

    dl_insert_last(headR, tailR, digit); // Insert the quotient digit at the end of the result linked list.

    temp = temp->next; // Move to the next digit of the dividend to bring it down in the next iteration.
  }

  remove_leading_zeroes(headR, tailR); // Remove leading zeroes from the result linked list to get the final quotient.

  return SUCCESS; // Return success as we have successfully performed the division operation.
}

