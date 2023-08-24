#include "monty.h"

/**
 * rotl_op - func rotates the 1st element to the bottom and  the 2nd to the top
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void rotl_op(stack_t **head, unsigned int line_no)
{
	stack_t *curr1 = NULL;
	stack_t *curr2 = NULL;
	(void)line_no;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	curr1 = (*head)->next;
	curr2 = *head;

	for (; curr2->next != NULL; curr2 = curr2->next)
		;

	curr1->prev = NULL;
	curr2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = curr2;
	*head = curr1;
}

/**
 * rotr_op - function reverses the stack
 * @head: pointer to the head of the linked list
 * @line_no: line number
 */
void rotr_op(stack_t **head, unsigned int line_no)
{
	stack_t *curr = NULL;
	(void)line_no;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	curr = *head;

	for (; curr->next != NULL; curr = curr->next)
		;

	curr->prev->next = NULL;
	curr->next = *head;
	curr->prev = NULL;
	(*head)->prev = curr;
	*head = curr;
}
