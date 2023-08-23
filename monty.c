#include "monty.h"
#include <stddef.h>

char *check_opcode(char *str, unsigned int n, stack_t *s);
var_t v;

/**
 * main - Entry point.
 * @ac: input number of arguments
 * @av: input arguments passed
 * Return: 0 (Success)
*/
int main(int ac, char **av)
{
	char *token, *token1, *cmd, *arg;
	size_t n = 0;
	ssize_t read;
	unsigned int line_num = 1;
	int num;
	stack_t *stack = NULL;
	const char *delim = " \t\n";
	void (*f)(stack_t **stack, unsigned int line_num);

	if (ac != 2)
		error_msg1();
	v.mfile = fopen(av[1], "r");
	if (!v.mfile)
		error_msg2(av);
	v.lineptr = NULL;
	while ((read = getline(&v.lineptr, &n, v.mfile)) != -1)
	{
		token = strtok(v.lineptr, delim);
		if (token == NULL || (strcmp(token, "Nop") == 0) || (token[0] == '#'))
		{
			line_num++;
			continue;
		}
		if (select_mode(token) == 1)
		{
			line_num++;
			continue;
		}
		cmd = check_opcode(token, line_num, stack);
		f = get_opcode(cmd);
		if (strcmp(cmd, "push") == 0)
		{
			token1 = strtok(NULL, delim);
			arg = test_int(token1, line_num, stack);
			num = atoi(arg);
			f(&stack, num);
		}
		else
			f(&stack, line_num);
		line_num++;
	}

	fclose(v.mfile);
	if (v.lineptr)
		free(v.lineptr);
	free_list(stack);
	return (0);
}

/**
 * check_opcode - Entry point-> Checks if the opcode is valid.
 * @str: input opcode to test
 * @n: input line number from the file
 * @s: input pointer to head node
 * Return: A valid opcode (Success)
*/
char *check_opcode(char *str, unsigned int n, stack_t *s)
{
	if (get_opcode(str) == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", n, str);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	(void)n;
	return (str);
}

/**
 * select_mode - Entry point-> It selects whether to store as stack or queue
 * @str: input string to determine selection
 * Return: 1 (Success) or 0 (Failed)
*/
int select_mode(char *str)
{
	if (strcmp(str, "stack") == 0)
	{
		v.mode = 1;
		return (1);
	}
	else if (strcmp(str, "queue") == 0)
	{
		v.mode = 2;
		return (1);
	}
	return (0);
}

/**
 * error_msg1 - Entry point-> Prints the error message.
*/
void error_msg1(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_msg2 - Entry point-> Prints error message.
 * @av: input arguments passed
*/
void error_msg2(char **av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
}
