#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: ptr to a struct
 *
 * Return: Address node where loop starts, NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *f = head;
	listint_t *s = head;

	while (s && f && f->next)
	{
		f = f->next->next;
		s = s->next;
		if (s == f)
		{
			s = head;
			while (f != s)
			{
				f = f->next;
				s = s->next;
			}
			return (s);
		}
	}
	return (NULL);
}
