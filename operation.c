#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

extern int sign; // This variable is used to store the sign of the result based on the input operands and operator.

/* This function performs addition of two large numbers stored as doubly linked lists. */
int list_com(Dlist **head1, Dlist **head2)
{
  /* Take 2 temp pointers to traverse the input linked lists */
  int list1_count = 0, list2_count = 0;
  Dlist *temp1, *temp2;
  temp1 = *head1, temp2 = *head2;

  /* Count the number of digits in both linked lists */
  while (temp1)
  {
    list1_count++;
    temp1 = temp1->next;
  }

  while (temp2)
  {
    list2_count++;
    temp2 = temp2->next;
  }

  /* If the number of digits in the first linked list is greater than the number of digits in the second linked list, then the first number is greater than the second number. If the number of digits in the first linked list is less than the number of digits in the second linked list, then the first number is less than the second number. If the number of digits in both linked lists is equal, then we need to compare each digit of both linked lists to determine which number is greater. */
  if (list1_count > list2_count)
  {
    return SUCCESS;
  }
  else if (list1_count < list2_count)
  {
    return FAILURE;
  }
  else if (list1_count == list2_count)
  {
    temp1 = *head1, temp2 = *head2;

    while (temp1 && temp2)
    {
      if (temp1->data > temp2->data)
      {
        return SUCCESS;
      }
      else if (temp1->data < temp2->data)
      {
        return FAILURE;
      }
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
  }
  return 2; // If both numbers are equal, then we return 2
}

/* This function performs addition of two large numbers stored as doubly linked lists. */
int operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char ch)
{
  /* Take 2 temp pointers to traverse the input linked lists */
  Dlist *tempt1 = *tail1;
  Dlist *tempt2 = *tail2;
  Dlist *temph1 = NULL, *temph2 = NULL;
  temph1 = *head1, temph2 = *head2;

  /* Remove the leading zeroes from both linked lists before performing the operation */
  remove_leading_zeroes(&temph1, &tempt1);
  remove_leading_zeroes(&temph2, &tempt2);

  /* Update the head and tail pointers of both linked lists after removing the leading zeroes */
  *head1 = temph1;
  *head2 = temph2;
  *tail1 = tempt1;
  *tail2 = tempt2;

  /* Perform the operation based on the operator */
  switch (ch)
  {
  case '+':
    addition(head1, tail1, head2, tail2, headR, tailR); // Call the addition function to perform addition of two large numbers stored as doubly linked lists.
    break;
  case '-':
    int ret = list_com(head1, head2); // Compare the two linked lists to determine which number is greater. If the first number is greater than the second number, then we will perform subtraction of the second number from the first number. If the first number is less than the second number, then we will perform subtraction of the first number from the second number and store the result in headR and tailR. If both numbers are equal, then we will perform subtraction of the first number from the second number and store the result in headR and tailR.

    /* Based on return value from list_com function, we will perform subtraction of the two linked lists */
    if (ret == SUCCESS)
    {
      subtraction(*head1, *tail1, *head2, *tail2, headR, tailR); // Call the subtraction function to perform subtraction of two large numbers stored as doubly linked lists.
    }
    else
    {
      subtraction(*head1, *tail1, *head2, *tail2, headR, tailR);
    }
    break;
  case '*':
    multiplication(*tail1, *tail2, headR, tailR); // Call the multiplication function to perform multiplication of two large numbers stored as doubly linked lists.
    break;
  case 'x':
    multiplication(*tail1, *tail2, headR, tailR); // Call the multiplication function to perform multiplication of two large numbers stored as doubly linked lists.
    break;
  case '/':
    ret = division(head1, tail1, head2, tail2, headR, tailR); // Call the division function to perform division of two large numbers stored as doubly linked lists.

    /* If the division is not possible, then we need to print an error message and return failure */
    if (ret != SUCCESS)
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] Division by zero not possible! \033[97m\n");
      return FAILURE;
    }
    break;

  default:
    printf("\033[1;97m[\033[1;91mERROR\033[1;97m] Invalid operator [\033[1;91mALLOWED OPERATORS : +-*/\033[97m]\n");
    return FAILURE;
  }

  /* If the sign variable is not zero, then we need to multiply the result with the sign variable to get the correct result. */
  if (sign != 0)
  {
    (*headR)->data *= sign;
  }

  /* If the result has leading zeroes, then we need to remove them before printing the result */
  if ((*headR)->data == 0 && (*headR)->next != NULL)
  {
    remove_leading_zeroes(headR, tailR);
  }

  /* Print the result */
  print_list(*headR);
  return SUCCESS;
}
