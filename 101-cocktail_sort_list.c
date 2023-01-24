#include "sort.h"

/**
 * swap_nodes - swaps a node with preceding node
 * @curr: current node
 * @nxt: next node whose position is to be occupied
*/
void swap_nodes(listint_t **head, listint_t *l, listint_t *r)
{
    listint_t *temp;

    if (l == NULL || l->next == NULL)
        return;

    temp = r->next;
    r->prev = l->prev;
    r->next = l;
    if (r->prev)
        r->prev->next = r;
    else
        *head = r;
    l->prev = r;
    l->next = temp;
    if (l->next)
        l->next->prev = l;
}

/**
 * cocktail_sort_list - sorts a doubly linked list 
 * in asc using Cocktail shaker sort
 * @list: Doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
    listint_t *node;
    bool swapped;

    if (!list || !(*list) || !(*list)->next)
        return;
        
    do
    {
        swapped = false;
        for (node = *list; node->next != NULL; node = node->next)
        {
            if (node->n > node->next->n)
            {
                swap_nodes(list, node, node->next);
                swapped = true;
                print_list(*list);
                node = node->prev;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        for (; node->prev != NULL; node = node->prev)
        {
            if (node->n < node->prev->n)
            {
                swap_nodes(list, node->prev, node);
                swapped = true;
                print_list(*list);
                node = node->next;
            }
        }
    } while(swapped);

}