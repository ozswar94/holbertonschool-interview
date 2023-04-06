#include "search.h"

/**
* check_linear - check for value in list linearly
* @list: ptr to list being searched
* @value: value
* @stop: ptr to node to stop searching at
*
* Return: ptr to first node where value, otherwise NULL
*/
skiplist_t *check_linear(skiplist_t *list, int value, skiplist_t *stop)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, stop->index);
	while (list != stop->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/**
* linear_skip - search for value in skip list of integers
* @list: ptr to head of skip list to search
* @value: value
*
* Return: ptr to first node where value, otherwise NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *stop;

	while (list)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				list->express->index, list->express->n);
		if (list->express->n >= value)
			return (check_linear(list, value, list->express));
		list = list->express;
		if (!list->express)
		{
			for (stop = list; stop->next; stop = stop->next)
				;
			return (check_linear(list, value, stop));
		}
	}
	return (NULL);
}
