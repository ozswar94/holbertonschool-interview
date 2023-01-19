#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * is_palindrome - detect if list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if the list is a plindrome otherwise 0
 */
int is_palindrome(listint_t **head)
{
	int i;
	int *list_tmp;
	unsigned int size;
	listint_t *tmp = *head;

	if (!(*head))
		return (1);

	for (size = 0; tmp; size++)
		tmp = tmp->next;

	list_tmp = malloc(sizeof(int) * size);
	if (!list_tmp)
		return (0);

	tmp = *head;
	for (i = 0; tmp; i++)
	{
		list_tmp[i] = tmp->n;
		tmp = tmp->next;
	}

	tmp = *head;
	for (i = size - 1; tmp; i--)
	{
		if (list_tmp[i] != tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
