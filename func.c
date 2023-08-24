#include "monty.h"

/**
 * get_opcodes - chooses the right opcode for the operation.
 *
 * @opcode: opcode passed
 *
 * Return: function pointer
 */
void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"queue", queue_op},
		{"stack", stack_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
			break;
		i++;
	}

	return (instruct[i].f);
}
