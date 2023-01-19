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
	unsigned int size;
	int i1, i2;
	int *list_tmp;
	listint_t *tmp = *head;

	if (!(*head))
		return (1);

	for (size = 0; tmp; size++)
		tmp = tmp->next;

	list_tmp = malloc(sizeof(int) * size);
	if (!list_tmp)
		return (0);

	tmp = *head;
	for (i2 = 0; tmp; i2++)
	{
		list_tmp[i2] = tmp->n;
		tmp = tmp->next;
	}

	i2 -= 1;
	for (i1 = 0; i1 < i2; i1++, i2--)
		if (list_tmp[i1] != list_tmp[i2])
			return (0);

	return (1);
}
