#include "sort.h"


/**
 * insertion_sort_list - sorts a list of int. in ascendig order (Inset. sort)
 * @list: pointer to pointer to data structur listint_t
 * Return: Void
 */

void swap_middle_nodes(listint_t **list);

void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	head = *list;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
		{
			/* EDGE case: 2 nodes */
			if (tmp->prev == NULL && tmp->next->next == NULL)
			{
				tmp->prev = tmp->next;
				tmp->next->next = tmp;
				tmp->next->prev = NULL;
				tmp->next = NULL;
				head = tmp->prev;
			}
			/* EDGE case: first node and number of nodes > 2*/
			else if (tmp->prev == NULL && tmp->next->next != NULL)
			{
				tmp->prev = tmp->next;
				tmp->next = tmp->next->next;
				tmp->prev->next = tmp;
				tmp->prev->prev = NULL;
				tmp->next->prev = tmp;
				head = tmp->prev;
			}
			/* EDGE case: middle nodes */
			else if (tmp->prev != NULL && tmp->next->next != NULL)
			{
				swap_middle_nodes(&tmp);
			}
			/* EDGE case: last node */
			else if (tmp->next->next == NULL)
			{
				tmp->next->next = tmp;
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
				tmp->prev = tmp->prev->next;
				tmp->next = NULL;
			}
			tmp = head;
			*list = tmp;
			print_list(tmp);
			continue;
		}
		tmp = tmp->next;
	}
}

/**
 * swap_middle_nodes - swaps nodes in middle of a list
 * @list: pointer to pointer to data structur listint_t
 * Return: Void
 */


void swap_middle_nodes(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	(*list)->next->next->prev = (*list);
	(*list)->next->prev = (*list)->prev;
	(*list)->prev = (*list)->next;
	(*list)->next = (*list)->prev->next;
	(*list)->prev->next = (*list);
	(*list)->prev->prev->next = (*list)->prev;
}
