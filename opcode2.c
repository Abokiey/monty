#include "monty.h"

/**
 * queue_op - formats the data to a queue(fifo)
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void queue_op(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;

	var.lifo = 0;
}

/**
 * stack_op - formats the data to a stack(lifo)
 * @head: head of the linked list
 * @line_no: line number;
 */
void stack_op(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;

	var.lifo = 1;
}

/**
 * add_op - adds the top two elements of the stack
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void add_op(stack_t **head, unsigned int line_no)
{
	int i = 0;
	stack_t *curr = NULL;

	curr = *head;

	for (; curr != NULL; curr = curr->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	curr = (*head)->next;
	curr->n += (*head)->n;
	pop_op(head, line_no);
}

/**
 * nop_op - does nothing
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void nop_op(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
}

/**
 * sub_op - subtracts the top element to the second top element of the stack
 * in the list
 * @head: pointer to the head of the linked list
 * @line_no: line number;
 */
void sub_op(stack_t **head, unsigned int line_no)
{
	int j = 0;
	stack_t *curr = NULL;

	curr = *head;

	for (; curr != NULL; curr = curr->next, j++)
		;

	if (j < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	curr = (*head)->next;
	curr->n -= (*head)->n;
	pop_op(head, line_no);
}
