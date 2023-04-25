#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked of integers
 * in ascending order using the insertion sort algorithm
 * @list: double pointer to head node of linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *curr_next;

	if (*list == NULL || (*list)->next == NULL)
		return;

	head = NULL;
	current = *list;

	while (current)
	{
		curr_next = current->next;
		insert_node(&head, &current);
		current = curr_next;
	}

	*list = head;
}


/**
 * insert_node - insert a node to a sorted doubly linked list
 * @list: double pointer to linked list
 * @node: node to add to linked list
 */
void insert_node(listint_t **list, listint_t **node)
{
	listint_t *head, *current;

	head = *list;
	current = *node;

	if (head == NULL)
	{
		current->next = NULL;
		current->prev = NULL;
		*list = current;
		return;
	}

	if (current->n <= head->n)
	{
		current->next = head;
		current->prev = head->prev;
		head->prev = current;
		*list = current;
		return;
	}

	while (head->next) {
		if (current->n <= head->next->n)
		{
			current->next = head->next;
			current->prev = head;
			head->next->prev = current;
			head->next = current;
			return;
		}
		head = head->next;
	}
	current->next = NULL;
	current->prev = head;
	head->next = current;
}
