#include "monty.h"

/**
 * div_op - divides the second element by the top element of the stack
 * in a list
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void div_op(stack_t **head, unsigned int line_no)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *head;

	for (; curr != NULL; curr = curr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	curr = (*head)->next;
	curr->n /= (*head)->n;
	pop_op(head, line_no);
}

/**
 * mul_op - multiplies the top element to the second top element of the stack
 * of the list
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void mul_op(stack_t **head, unsigned int line_no)
{
	int j = 0;
	stack_t *curr = NULL;

	curr = *head;

	for (; curr != NULL; curr = curr->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	curr = (*head)->next;
	curr->n *= (*head)->n;
	pop_op(head, line_no);
}

/**
 * mod_op - calculates the whole division of the second element
 * with the top element of the stack
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void mod_op(stack_t **head, unsigned int line_no)
{
	int j = 0;
	stack_t *curr = NULL;

	curr = *head;

	for (; curr != NULL; curr = curr->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	curr = (*head)->next;
	curr->n %= (*head)->n;
	pop_op(head, line_no);
}
/**
 * pchar_op -function prints the value of the first element
 * of a character
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void pchar_op(stack_t **head, unsigned int line_no)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * pstr_op - prints the whole string of the stack
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void pstr_op(stack_t **head, unsigned int line_no)
{
	stack_t *curr;
	(void)line_no;

	curr = *head;

	while (curr && curr->n > 0 && curr->n < 128)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
