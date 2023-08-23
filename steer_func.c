#include "monty.h"

/**
 * get_opcode - Entry point-> It matches opcode to the corresponding function.
 * @str: input opcode to be matched
 * Return: matched function
*/
void (*get_opcode(char *str))(stack_t **, unsigned int)
{
	instruction_t op[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{NULL, NULL}
	};

	int b = 0;

	while (op[b].opcode != NULL)
	{
		if (strcmp(op[b].opcode, str) == 0)
			return (op[b].f);
		b++;
	}
	return (NULL);
}

/**
 * test_int - Entry point-> It tests if argument passed to push is an integer.
 * @str: input arguments to push
 * @n: input line number
 * @h: input pointer to the head node
 * Return: string integer (Success)
*/
char *test_int(char *str, unsigned int n, stack_t *h)
{
	int b;

	if (str == NULL)
	{
		fprintf(stderr, "L%u: Usage: push integer\n", n);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	for (b = 0; str[b] != '\0'; b++)
	{
		if (str[0] == '-')
			continue;
		if (isdigit(str[b]) == 0)
		{
			fprintf(stderr, "L%u: Usage: push integer\n", n);
			fclose(v.mfile);
			free(v.lineptr);
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
	return (str);
}

/**
 * free_list - Entry point-> It frees a malloc'ed linked list.
 * @head: input pointer to the first node
*/
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
