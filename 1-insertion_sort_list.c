#include "sort.h"


/**
 * insertion_sort_list - sorts a list of int. in ascendig order (Insertion sort)
 * @list: pointer to pointer to data structur listint_t
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *tmp = NULL;

	/* Guard conditions for Null node */
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
				tmp->next->next->prev = tmp;
				tmp->next->prev = tmp->prev;
				tmp->prev = tmp->next;
				tmp->next = tmp->prev->next;
				tmp->prev->next = tmp;
				tmp->prev->prev->next = tmp->prev;
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
			print_list(tmp);
			continue;
		}
		tmp = tmp->next;
	}
}
