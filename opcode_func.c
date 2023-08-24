#include "monty.h"

/**
 * push_opcode - Entry point-> It adds a node to stack.
 * @stack: input pointer to the head node
 * @line_num: input line number in the file
*/
void push_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *added, *temp;

	added = malloc(sizeof(stack_t));
	if (!added)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	added->n = line_num;

	if (v.mode == 1 || !v.mode)
	{
		added->next = *stack;
		added->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = added;
		*stack = added;
	}
	else if (v.mode == 2)
	{
		if (*stack == NULL)
		{
			added->prev = NULL;
			added->next = NULL;
			*stack = added;
		}
		else
		{
			temp = *stack;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = added;
			added->prev = temp;
			added->next = NULL;
		}
	}
}

/**
 * pall_opcode - Entry point-> It prints stack_list.
 * @stack: input pointer to head node
 * @line_num: input line number in the file
*/
void pall_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (stack != NULL)
	{
		temp = *stack;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
	(void)line_num;
}

/**
 * pint_opcode - Entry point-> It prints data at the top of stack.
 * @stack: input pointer to head node
 * @line_num: input line number in the file
*/
void pint_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (temp != NULL)
		printf("%i\n", temp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_opcode - Entry point-> It deletes data at the top of a stack.
 * @stack: input pointer to head node
 * @line_num: input line number in the file
*/
void pop_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, "L%u: Can't pop an empty stack\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
		temp = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap_opcode - Entry point-> It seap top 2 elements of a stack.
 * @stack: input pointer to head node
 * @line_num: input line number in the file
*/
void swap_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *temp1 = *stack;
	unsigned int b = 0;

	while (temp1)
	{
		temp1 = temp1->next;
		b++;
	}
	if (b >= 2)
	{
		temp = *stack;
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->prev = NULL;
		if (temp->next != NULL)
			temp->next->prev = *stack;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: Can't swap, stack too short\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}
