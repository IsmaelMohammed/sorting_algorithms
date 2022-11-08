#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - implementation of insertion sort
 * @list: doubly linked list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cursor = NULL, *cursor_2 = NULL;
	int first, second;

	if (list == NULL)
		return;
	if ((*list)->next == NULL)
		return;

	cursor = *list;
	while (cursor != NULL)
	{
		if (cursor->prev != NULL)
		{
			cursor_2 = cursor;
			cursor = cursor->next;
			while (cursor_2->prev != NULL)
			{
				first = (cursor_2->prev)->n;
				second = cursor_2->n;
				if (first <= second)
					break;
				swap_nodes(cursor_2->prev, cursor_2);
				if (cursor_2->prev == NULL)
					*list = cursor_2;
				print_list(*list);
			}
		}
		else
			cursor = cursor->next;
	}
}

/**
 * swap_nodes - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 *
 * Return: void
 */
void swap_nodes(listint_t *first, listint_t *second)
{
	if (first->prev != NULL)
		(first->prev)->next = second;
	if (second->next != NULL)
		(second->next)->prev = first;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	second->next = first;
}
