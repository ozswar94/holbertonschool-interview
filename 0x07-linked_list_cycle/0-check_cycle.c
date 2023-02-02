#include "lists.h"

/**
 * check_cycle - Checks cycle
 * @list: Linked list
 * Return: 0 or 1
 */
int check_cycle(listint_t *list)
{
	listint_t *h1 = list, *h2 = list;

	while (h1 && h2)
	{
		if (!(h2->next) || !(h2->next->next))
			break;
		h1 = h1->next;
		h2 = h2->next->next;
		if (h1 == h2)
			return (1);
	}
}
