#include "monty.h"

/**
 * add_opcode - Entry point-> It adds two top elements of the stack.
 * @stack: input pointer to head node
 * @line_num: input line number from the file
*/
void add_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *temp1 = *stack;
	unsigned int b = 0;
	int added;

	while (temp1)
	{
		temp1 = temp1->next;
		b++;
	}
	if (b >= 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		added = temp->n + (*stack)->n;
		(*stack)->n = added;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: Can't add, stack too short\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub_opcode - Entry point-> It subtract top two elements in a stack.
 * @stack: input pointer to head node
 * @line_num: input line number from the file
*/
void sub_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *temp1 = *stack;
	unsigned int b = 0;
	int sub;

	while (temp1)
	{
		temp1 = temp1->next;
		b++;
	}
	if (b >= 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		sub = (*stack)->n - temp->n;
		(*stack)->n = sub;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: Can't sub, stack too short\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_opcode - Entry point-> It divide the second top by top element of stack.
 * @stack: input pointer to head node;
 * @line_num: input line number from file
*/
void div_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *temp1 = *stack;
	unsigned int b = 0;
	int div;

	while (temp1)
	{
		temp1 = temp1->next;
		b++;
	}
	if (b >= 2)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_num);
			fclose(v.mfile);
			free(v.lineptr);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		temp = *stack;
		*stack = (*stack)->next;
		div = (*stack)->n / temp->n;
		(*stack)->n = div;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: Can't div, stack too short\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_opcode - Entry point-> It multiplies second top by the top of stack.
 * @stack: input pointer to head node
 * @line_num: input line number from the file
*/
void mul_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *temp1 = *stack;
	unsigned int b = 0;
	int mul;

	while (temp1)
	{
		temp1 = temp1->next;
		b++;
	}
	if (b >= 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		mul = (*stack)->n * temp->n;
		(*stack)->n = mul;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: Can't mul, stack too short\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_opcode - Entry point-> It finds module of top two element of a stack.
 * @stack: input pointer to the head node
 * @line_num: input line number from the file
*/
void mod_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *temp1 = *stack;
	unsigned int b = 0;
	int mod;

	while (temp1)
	{
		temp1 = temp1->next;
		b++;
	}
	if (b >= 2)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_num);
			fclose(v.mfile);
			free(v.lineptr);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		temp = *stack;
		*stack = (*stack)->next;
		mod = (*stack)->n % temp->n;
		(*stack)->n = mod;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: Can't mod, stack too short\n", line_num);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}
