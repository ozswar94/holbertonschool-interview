#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to list to be freed
 * @number: value of the node
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp;

	new = (listint_t *)malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (!(*head))
	{
		*head = new;
		return (new);
	}

	if (number < (*head)->n)
	{
		new->next = (*head);
		*head = new;
		return (new);
	}

	tmp = *head;
	while (tmp->next && tmp->next->n < number)
		tmp = tmp->next;

	new->next = tmp->next;
	tmp->next = new;

	return (new);
}
