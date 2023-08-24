#include "monty.h"

/**
 * push_op - pushes an element to a list
 * @head: pointer to the linked list
 * @line_no: line number
 */
void push_op(stack_t **head, unsigned int line_no)
{
	int m, j;

	if (!var.arg)
	{
		dprintf(2, "L%u: ", line_no);
		dprintf(2, "usage: push integer\n");
		free_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; var.arg[j] != '\0'; j++)
	{
		if (!isdigit(var.arg[j]) && var.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_no);
			dprintf(2, "usage: push integer\n");
			free_var();
			exit(EXIT_FAILURE);
		}
	}

	m = atoi(var.arg);

	if (var.lifo == 1)
		add_dnodeint(head, m);
	else
		add_dnodeint_end(head, m);
}

/**
 * pall_op - prints all values on the stack of a linked list
 * @head: pointer to the linked list
 * @line_no: line numbers
 */
void pall_op(stack_t **head, unsigned int line_no)
{
	stack_t *curr;
	(void)line_no;

	curr = *head;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint_op - prints the value at the top of the stack of the linked list
 * @head: head of the linked list
 * @line_no: line number
 */
void pint_op(stack_t **head, unsigned int line_no)
{
	(void)line_no;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_no);

		dprintf(2, "can't pint, stack empty\n");
		free_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * pop_op - removes the top element of the stack of a list
 * @head: poiner to the linked list
 * @line_no: line number
 */
void pop_op(stack_t **head, unsigned int line_no)
{
	stack_t *curr;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}
	curr = *head;
	*head = (*head)->next;
	free(curr);
}

/**
 * swap_op - swaps the top two elements of the stack in a list
 * @head: pointr to the head of the linked list
 * @line_no: line number
 */
void swap_op(stack_t **head, unsigned int line_no)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *head;

	for (; curr != NULL; curr = curr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	curr = *head;
	*head = (*head)->next;
	curr->next = (*head)->next;
	curr->prev = *head;
	(*head)->next = curr;
	(*head)->prev = NULL;
}
