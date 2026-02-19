#ifndef DLL_H /* Include guard to prevent multiple inclusions of this header file */
#define DLL_L /* Define the macro for the include guard */

/**
 * @file main.h
 * @author Manu H P
 * @project: Arbitrary Precision Calculator(APC)
 * @tech_stack: C language, Doubly Linked List, Command Line Arguments, Dynamic Memory Allocation
 * @description: This header file contains the structure definition for a doubly linked list and function prototypes
 * @brief This header file contains the structure definition for a doubly linked list and function prototypes for performing arithmetic operations on large numbers represented as linked lists.
 */

/* Include necessary header files for input/output operations, dynamic memory allocation, and string manipulation */
#include <stdio.h>  // Header file for input/output operations such as printf and scanf.
#include <stdlib.h> // Header file for dynamic memory allocation functions such as malloc and free.
#include <string.h> // Header file for string manipulation functions such as strlen and strcpy.

/* Macro definitions for success and failure status */
#define SUCCESS 0
#define FAILURE -1

/* Structure definition for a node in a doubly linked list */
typedef struct node
{
  int data;
  struct node *prev;
  struct node *next;
} Dlist;

/* Function prototypes for validation and operand handling */
int only_number(char *str1, char *str2);
void read_operands(char *str1, char *str2, char *argv[], int check);
int validation(char *argv[], char *str1, char *str2, char *ch);

/* Function prototypes for linked list insertion deletion operations */
void remove_leading_zeroes(Dlist **head, Dlist **tail);
void dl_insert(Dlist **head, Dlist **tail, char *str);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_delete_list(Dlist **head, Dlist **tail);

/* Function prototype for comparing two linked lists representing large numbers */
int list_com(Dlist **head1, Dlist **head2);

/* Function prototypes for arithmetic operations on large numbers represented as linked lists */
int operation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char ch);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Function prototype for printing the result */
void print_list(Dlist *head);

#endif /* End of include guard */