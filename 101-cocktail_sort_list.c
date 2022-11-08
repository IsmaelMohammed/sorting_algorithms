#include "sort.h"

/**
 * cocktail_sort_list - cocktail sorting method
 * @list: head of linked list
 *
 * Return: void function
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swapped = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if ((temp->n) > ((temp->next)->n))
			{
				swap_link(temp, temp->next, list);
				print_list(*list);
				swapped = 1;
				temp = temp->prev;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if ((temp->n) < ((temp->prev)->n))
			{
				swap_link(temp->prev, temp, list);
				swapped = 1;
				print_list(*list);
				temp = temp->next;
			}
		}
	} while (swapped);
}

/**
 * swap_link - swap adjacent nodes of a doubly linked list
 * @first: first node
 * @second: second node
 * @head: head of list
 *
 * Return: void
 */
void swap_link(listint_t *first, listint_t *second, listint_t **head)
{
	listint_t *a = first->prev;
	listint_t *b = second->next;

	if (a != NULL)
		(a)->next = second;
	else
		*head = second;
	first->prev = second;
	first->next = b;
	second->prev = a;
	second->next = first;
	if (b)
		(b)->prev = first;
}
