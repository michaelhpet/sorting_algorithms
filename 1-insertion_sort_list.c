#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked of integers
 * in ascending order using the insertion sort algorithm
 * @list: double pointer to head node of linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp_current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{

			tmp_current = current;

			if (current->next)
				(current->next)->prev = tmp_current->prev;

			(current->prev)->next = tmp_current->next;
			current = current->prev;
			tmp_current->prev = current->prev;
			tmp_current->next = current;

			if (current->prev)
				(current->prev)->next = tmp_current;

			current->prev = tmp_current;

			if (tmp_current->prev == NULL)
				*list = tmp_current;

			print_list(*list);
			current = current->prev;
		}
		current = current->next;
	}
}
