#include "sort.h"

/**
 * swap - function swaping two nodes
 * @list: pointer to first item in a list
 * @node1: pointer to node1
 * @node2: pointer to node2
 *
 * Return: nothing
 */

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
        node1->next = node2->next;
        if (node1->next)
        {
                node1->next->prev = node1;
        }
        node2->next = node1;
        node2->prev = node1->prev;
        node1->prev = node2;
        if (node2->prev)
        {
                node2->prev->next = node2;
        }
        else
        {
                *list = node2;
        }
}

/**
 * insertion_sort_list - sorting list by insertion algorithm
 * @list: pointer to first item in a list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
        listint_t *node;

        if (!list || !*list || !(*list)->next)
                return;

        node = (*list)->next;
        while (node)
        {
                while (node->prev && node->n < node->prev->n)
                {
                        swap(list, node->prev, node);
                        print_list(*list);
                }
                node = node->next;
        }
}
