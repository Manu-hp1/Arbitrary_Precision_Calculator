#include "main.h" // This file includes the main header file which contains the structure definition and function prototypes.

/* This function performs insertion of digits from the input string into the linked list. */
void dl_insert(Dlist **head, Dlist **tail, char *str)
{
  int i = 0;
  /* Loop through the input string and insert each digit into the linked list. */
  while (str[i])
  {
    int data = str[i] - '0';
    dl_insert_last(head, tail, data); // Insert the digit at the end of the linked list
    i++;
  }
}

/* This function performs insertion of a digit at the beginning of the linked list. */
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
  // Allocating the memory for new node
  Dlist *newnode = malloc(sizeof(Dlist));
  
  // If the node is not created the returning failure
  if (!newnode)
  {
    return FAILURE;
  }

  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = NULL;

  // If the list is empty then inserting the node as first node
  if (*head == NULL)
  {
    *head = *tail = newnode;
    return SUCCESS;
  }

  newnode->next = *head;
  (*head)->prev = newnode;
  *head = newnode;
  return SUCCESS;
}

/* This function performs insertion of a digit at the end of the linked list. */
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
  // Allocating the memory for new node
  Dlist *new = malloc(sizeof(Dlist));

  // If the node is not created the returning failure
  if (!new)
  {
    return FAILURE;
  }
  new->data = data;
  new->prev = NULL;
  new->next = NULL;

  // If the list is empty then inserting the node as first node
  if (!*head && !*tail)
  {
    *head = *tail = new;
    return SUCCESS;
  }
  new->prev = *tail;
  (*tail)->next = new;
  *tail = new;
  return SUCCESS;
}

/* This function performs deletion of the entire linked list and frees the dynamically allocated memory. */
int dl_delete_list(Dlist **head, Dlist **tail)
{
  if (*head == NULL)
  {
    return FAILURE;
  }

  Dlist *temp = *head;

  while (temp != NULL)
  {
    *head = temp->next;
    free(temp);
    temp = *head;
  }

  *head = NULL;
  *tail = NULL;
  return SUCCESS;
}

/* This function removes the leading zeroes from the linked list. */
void remove_leading_zeroes(Dlist **head, Dlist **tail)
{
  /* Loop upto the non zero element found */
  while (*head && (*head)->data == 0 && (*head)->next)
  {
    Dlist *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
  }
}