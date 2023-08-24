#include "monty.h"

data_t var;

/**
 * free_var - function frees global variables
 *
 */
void free_var(void)
{
	free_dlistint(var.head);
	free(var.buffer);
	fclose(var.fd);
}

/**
 * start_var - func helps initialize global variables
 * @fd: file descriptor
 */
void start_var(FILE *fd)
{
	var.lifo = 1;
	var.curr = 1;
	var.arg = NULL;
	var.head = NULL;
	var.fd = fd;
	var.buffer = NULL;
}

/**
 * open_input_file - checks if the file can be open or exists
 * @argc: command-line argument count
 * @argv: argument vector
 * Return: pointer to the open file
 */

FILE *open_input_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = open_input_file(argc, argv);
	start_var(fd);
	nlines = getline(&var.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = strtok(var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", var.curr);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_var();
				exit(EXIT_FAILURE);
			}
			var.arg = strtok(NULL, " \t\n");
			f(&var.head, var.curr);
		}
		nlines = getline(&var.buffer, &size, fd);
		var.curr++;
	}

	free_var();

	return (0);
}
