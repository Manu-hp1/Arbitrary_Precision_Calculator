#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

extern int sign; // This variable is used to store the sign of the result based on the input operands and operator.

/* This function validates the input operands and operator, and prepares the operands for further processing. */
void read_operands(char *str1, char *str2, char *argv[], int check)
{
  int i = 1;
  /* If check is not 5, then we need to read the first operand from argv[1] and store it in str1 */
  if (check != 5) 
  {
    while (argv[1][i])
    {
      str1[i - 1] = argv[1][i];
      i++;
    }
  }
  i = 1;
  /* If check is not 4, then we need to read the second operand from argv[3] and store it in str2 */
  if (check != 4) 
  {
    while (argv[3][i])
    {
      str2[i - 1] = argv[3][i];
      i++;
    }
  }
}

/* This function checks if the input strings contain only numeric characters. */
int only_number(char *str1, char *str2)
{
  int i = 0;
  while (str1[i])
  {
    if (!(str1[i] >= 48 && str1[i] <= 57))
    {
      return FAILURE;
    }
    i++;
  }
  i = 0;
  while (str2[i])
  {
    if (!(str2[i] >= 48 && str2[i] <= 57))
    {
      return FAILURE;
    }
    i++;
  }
  return SUCCESS;
}

/* This function validates the input operands and operator, and prepares the operands for further processing. */
int validation(char *argv[], char *str1, char *str2, char *ch)
{
  int check = 0, i = 0;
  char *operator = "+-*x/";

  /* Check if the operator is valid */
  while (operator[i])
  {
    if (operator[i] == *ch)
      break;
    i++;
  }
  if (i == strlen(operator))
  {
    printf("\033[1;97m[\033[1;91mERROR\033[1;97m] Invalid operator [\033[1;91mALLOWED OPERATORS : +-*/\033[97m]\n");
    exit(1);
  }

  /* Check the signs of the operands and store the operands for further processing */
  if (argv[1][0] == argv[3][0] && argv[3][0] == '+') // If both operands are positive
  {
    if (argv[1][1] == '-' || argv[1][1] == '+' || argv[3][1] == '-' || argv[3][1] == '+') // If the sign is not at the first position, then it is an invalid operand
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }

    check = 1;
    sign = 1;
    read_operands(str1, str2, argv, check);
    return check;
  }
  else if (argv[1][0] == argv[3][0] && argv[3][0] == '-') // If both operands are negative
  {
    if (argv[1][1] == '-' || argv[1][1] == '+' || argv[3][1] == '-' || argv[3][1] == '+')
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }
    check = 2;
    sign = -1;
    if (*ch == '+') // If the operator is '+' and both operands are negative, then the result will be negative
    {
      *ch = '+';
      sign = -1;
    }
    else if (*ch == '-') // If the operator is '-' and both operands are negative, then the result will be positive
    {
      *ch = '-';
      sign = -1;
    }
    else if (*ch == '/') // If the operator is '/' and both operands are negative, then the result will be negative
    {
      sign = 1;
    }
    else if (*ch == '*' || *ch == 'x') // If the operator is '*' and both operands are negative, then the result will be positive
    {
      sign = 1;
    } 
    read_operands(str1, str2, argv, check);
    return check;
  }
  else if (argv[1][0] == '+' && argv[3][0] == '-') // If first operand is positive and second operand is negative
  {
    if (argv[1][1] == '-' || argv[1][1] == '+' || argv[3][1] == '-' || argv[3][1] == '+')
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }
    check = 3;
    sign = -1;
    if (*ch == '+') // If the operator is '+' and the first operand is positive, then the result will be negative
    {
      *ch = '-';
      sign = 1;
    }
    else if (*ch == '-') // If the operator is '-' and the first operand is positive, then the result will be negative
    {
      *ch = '+';
      sign = 1;
    }
    else if (*ch == '/' || *ch == '*' || *ch == 'x') // If the operator is '/' or '*' and the first operand is positive, then the result will be positive
    {
      sign = -1;
    }

    read_operands(str1, str2, argv, check);
    return check;
  }
  else if (argv[1][0] == '-' && argv[3][0] == '+') // If first operand is negative and second operand is positive
  {
    if (argv[1][1] == '-' || argv[1][1] == '+' || argv[3][1] == '-' || argv[3][1] == '+')
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }
    check = 3;
    sign = -1;
    if (*ch == '+') // If the operator is '+' and the first operand is negative, then the result will be subtraction
    {
      *ch = '-';
      sign = -1;
    }
    else if (*ch == '-') // If the operator is '-' and the first operand is negative, then the result will be addition
    {
      *ch = '+';
      sign = -1;
    }
    else if (*ch == '/' || *ch == '*' || *ch == 'x') // If the operator is '/' or '*' and the first operand is negative, then the result will be negative
    {
      sign = -1;
    }
    else if (*ch == '/' || *ch == '*' || *ch == 'x') // If the operator is '/' or '*' and the first operand is positive, then the result will be positive
    {
      sign = 1;
    }
    read_operands(str1, str2, argv, check);
    return check;
  }
  else if (argv[1][0] == '-' && argv[3][0] == '+') // If first operand is negative and second operand is positive
  {
    if (argv[1][1] == '-' || argv[1][1] == '+' || argv[3][1] == '-' || argv[3][1] == '+') // If the sign is not at the first position, then it is an invalid operand
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }
    check = 3;
    sign = -1;

    if (*ch == '+') // If the operator is '+' and the first operand is negative, then the result will be negative
    {
      *ch = '-';
    }
    else if (*ch == '-') // If the operator is '-' and the first operand is negative, then the result will be positive
    {
      *ch = '+';
    }
    else if (*ch == '/' || *ch == '*' || *ch == 'x') // If the operator is '/' or '*' and the first operand is negative, then the result will be negative
    {
      sign = -1;
    }
    else if (*ch == '/' || *ch == '*' || *ch == 'x') // If the operator is '/' or '*' and the first operand is positive, then the result will be positive
    {
      sign = 1;
    }
    read_operands(str1, str2, argv, check);
    return check;
  }
  /* If one of the operands has a sign and the other operand does not have a sign */
  else if ((argv[1][0] == '-' && argv[3][0] != '-' && argv[3][0] != '+') || (argv[1][0] == '+' && argv[3][0] != '-' && argv[3][0] != '+'))
  {
    if (argv[1][1] == '-' || argv[1][1] == '+') // If the first operand has a sign, but it is not at the first position, then it is an invalid operand
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }
    check = 4;
    if (*ch == '-' && argv[1][0] == '-') // If the operator is '-' and the first operand is negative, then the result will be positive
    {
      *ch = '+';
      sign = -1;
    }
    else if (*ch == '+' && argv[1][0] == '-') // If the operator is '+' and the first operand is negative, then the result will be negative
    {
      *ch = '-';
      sign = -1;
    }
    else if (*ch == '+' && argv[1][0] == '+') // If the operator is '+' and the first operand is positive, then the result will be positive
    {
      *ch = '+';
      sign = 1;
    }
    else if (*ch == '-' && argv[1][0] == '+') // If the operator is '-' and the first operand is positive, then the result will be negative
    {
      *ch = '-';
      sign = 1;
    }
    else if ((*ch == '/' || *ch == '*' || *ch == 'x') && argv[1][0] == '-') // If the operator is '/' or '*' and the first operand is negative, then the result will be negative
    {
      sign = -1;
    }
    else if ((*ch == '/' || *ch == '*' || *ch == 'x') && argv[1][0] == '+') // If the operator is '/' or '*' and the first operand is positive, then the result will be positive
    {
      sign = 1;
    }
    else
    {
      sign = -1;
    }
    read_operands(str1, str2, argv, check);
    return check;
  }
  /* If one of the operands has a sign and the other operand does not have a sign */
  else if ((argv[3][0] == '-' && argv[1][0] != '-' && argv[1][0] != '+') || (argv[3][0] == '+' && argv[1][0] != '-' && argv[1][0] != '+'))
  {
    if (argv[3][1] == '-' || argv[3][1] == '+') // If the second operand has a sign, but it is not at the first position, then it is an invalid operand
    {
      printf("\033[1;97m[\033[1;91mERROR\033[1;97m] INVALID OPERANDS\033[97m\n");
      exit(0);
    }
    check = 5;
    if (*ch == '-' && argv[3][0] == '-') // If the operator is '-' and the second operand is negative, then the result will be positive
    {
      *ch = '+';
      sign = 1;
    }
    else if (*ch == '+' && argv[3][0] == '-') // If the operator is '+' and the second operand is negative, then the result will be negative
    {
      *ch = '-';
      sign = 1;
    }
    else if (*ch == '+' && argv[3][0] == '+') // If the operator is '+' and the second operand is positive, then the result will be positive
    {
      *ch = '+';
      sign = 1;
    }
    else if (*ch == '-' && argv[3][0] == '+') // If the operator is '-' and the second operand is positive, then the result will be negative
    {
      *ch = '-';
      sign = 1;
    }
    else if ((*ch == '/' || *ch == '*' || *ch == 'x') && argv[3][0] == '-') // If the operator is '/' or '*' and the second operand is negative, then the result will be negative
    {
      sign = -1;
    }
    else if ((*ch == '/' || *ch == '*' || *ch == 'x') && argv[3][0] == '+') // If the operator is '/' or '*' and the second operand is positive, then the result will be positive
    {
      sign = 1;
    }
    read_operands(str1, str2, argv, check);
    return check;
  }
  else
  {
    sign = 1;
    return 6;
  }
  return SUCCESS;
}