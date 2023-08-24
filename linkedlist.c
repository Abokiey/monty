#include "monty.h"

/**
 *add_dnodeint_end - add a node at the end of the list
 *@h: pointer to the head of linked list
 *@n: data
 *Return: updated doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **h, const int n)
{
	stack_t *tmp, *curr;

	if (h == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*h == NULL)
	{
		tmp->next = *h;
		tmp->prev = NULL;
		*h = tmp;
		return (*h);
	}
	curr = *h;
	while (curr->next)
		curr = curr->next;
	tmp->next = curr->next;
	tmp->prev = curr;
	curr->next = tmp;
	return (curr->next);
}

/**
 *add_dnodeint - add a node at the begining of a linkedlist
 *@h: pointer to the head of linked list
 *@n: data
 *Return: updated linked list
 */
stack_t *add_dnodeint(stack_t **h, const int n)
{
	stack_t *tmp;

	if (h == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (*h == NULL)
	{
		tmp->next = *h;
		tmp->prev = NULL;
		*h = tmp;
		return (*h);
	}
	(*h)->prev = tmp;
	tmp->next = (*h);
	tmp->prev = NULL;
	*h = tmp;
	return (*h);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @h: pointer to the head of the list
 */
void free_dlistint(stack_t *h)
{
	stack_t *temp;

	while ((temp = h) != NULL)
	{
		h = h->next;
		free(temp);
	}
}
