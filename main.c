#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

int sign = 0; // This variable is used to store the sign of the result based on the input operands and operator.

int main(int argc, char *argv[])
{
  /* If the number of arguments is not 4, then we need to print an error message and return failure */
  if (argc != 4)
  {
    printf("\033[1;97m[\033[1;91mNOTE\033[1;97m] ./a.out <operand1> <operator> <opernad2>\n");
    return 0;
  }

  /* Take 3 linked lists to store the input operands and the result of the operation. */
  Dlist *head1, *tail1;
  head1 = tail1 = NULL;
  Dlist *head2, *tail2;
  head2 = tail2 = NULL;
  Dlist *headR, *tailR;
  headR = tailR = NULL;

  /* Take a variable to store the operator and two variables to store the input operands as strings. */
  char ch = argv[2][0];

  /* Take two variables to store the input operands as strings. We will be using these variables to validate the input operands and to perform the operations. */
  char *str1, *str2;
  str1 = str2 = NULL;

  str1 = malloc((sizeof(char) * (strlen(argv[1]))) + 1);
  str2 = malloc((sizeof(char) * (strlen(argv[3]))) + 1);

  int ret = validation(argv, str1, str2, &ch);

  /** INFO:
   * Based on the return value from the validation function, we will be inserting the input operands into the linked lists.
   * If the return value is 0, then both operands do not have a sign.
   * If the return value is 1, then both operands are positive.
   * If the return value is 2, then both operands are negative.
   * If the return value is 3, then both operands have a different sign.
   * If the return value is 4, then only the second operand has a sign.
   * If the return value is 5, then only the first operand has a sign.
   * If the return value is 6, then both operands have a sign.
   */
  if (ret == 6)
  {
    strcpy(str1, argv[1]); // Copy the first operand from argv[1] to str1, so that we can insert it into the linked list.
    strcpy(str2, argv[3]); // Copy the second operand from argv[3] to str2, so that we can insert it into the linked list.
  }
  else if (ret == 4)
  {
    strcpy(str2, argv[3]); // Copy the second operand from argv[3] to str2, so that we can insert it into the linked list.
  }
  else if (ret == 5)
  {
    strcpy(str1, argv[1]); // Copy the first operand from argv[1] to str1, so that we can insert it into the linked list.
  }

  /* If the input operands contain any non-numeric characters, then we need to print an error message and return failure */
  if (only_number(str1, str2) == FAILURE)
  {
    printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS [\033[1;91mALLOWED TYPE - INTEGER\033[1;97m]\033[97m\n");
    exit(0);
  }
  dl_insert(&head1, &tail1, str1); // Insert the first operand into the linked list.
  dl_insert(&head2, &tail2, str2); // Insert the second operand into the linked list.

  /* Perform the operation based on the operator and the input operands. */
  operation(&head1, &tail1, &head2, &tail2, &headR, &tailR, ch);

  /* Free the dynamically allocated memory for the input operands. */
  free(str1);
  free(str2);
  return 0;
}