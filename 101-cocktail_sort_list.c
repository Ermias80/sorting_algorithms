#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1 == NULL || node2 == NULL || node1 == node2)
        return;

    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    if (node1->next == node2)
    {
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->next = node1;
        
        if (node1->next)
            node1->next->prev = node1;
        if (node2->prev)
            node2->prev->next = node2;
    }
    else
    {
        listint_t *tmp_prev1 = node1->prev;
        listint_t *tmp_next1 = node1->next;
        listint_t *tmp_prev2 = node2->prev;
        listint_t *tmp_next2 = node2->next;

        node1->prev = tmp_prev2;
        node1->next = tmp_next2;
        node2->prev = tmp_prev1;
        node2->next = tmp_next1;

        if (tmp_prev1)
            tmp_prev1->next = node2;
        if (tmp_next1)
            tmp_next1->prev = node2;
        if (tmp_prev2)
            tmp_prev2->next = node1;
        if (tmp_next2)
            tmp_next2->prev = node1;

        if (node1 == *list)
            *list = node2;
        else if (node2 == *list)
            *list = node1;
    }
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 0;
    listint_t *current = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (current = current->prev; current != NULL; current = current->prev)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}
