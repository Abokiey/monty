#include "monty.h"

/**
 * pchar_opcode - Entry point-> It prints a char at top of the stack.
 * @stack: input pointer to head node
 * @line_num: input line number from the file
*/
void pchar_opcode(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: Can't pchar, stack empty\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);/* free_list(*stack) */
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: Can't pchar, value out of range\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_opcode - Entry point-> It prints string starting at the top of stack.
 * @stack: input pointer to head node;
 * @line_num: input line number from the file
*/
void pstr_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_num;
}

/**
 * rotl_opcode - Entry point-> It rotates the stack to the top.
 * @stack: input pointer to head node
 * @line_num: input line number from the file
*/
void rotl_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next->next = NULL;
		temp = NULL;
	}
	(void)line_num;
}

/**
 * rotr_opcode - Entry point-> It rotates the stack to bottom.
 * @stack: input pointer to the head node
 * @line_num: input line number from the file
*/
void rotr_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack)
	{
		while (temp->next != NULL)
			temp = temp->next;
		(*stack)->prev = temp;
		temp->next = *stack;
		temp->prev->next = NULL;
		temp->prev = NULL;
		*stack = temp;
		temp = NULL;
	}
	(void)line_num;
}
