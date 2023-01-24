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
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using insertion sort
 * @list: doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *pre;

    if (list == NULL || *list == NULL)
        return;

    for (curr = *list; curr; curr = curr->next)/**curr starts at first node*/
    {
        for (pre = curr->prev; pre && pre->n > curr->n; pre = curr->prev)
        {
            swap_nodes(list, pre, curr);/**swaps nodes with prevoious*/
            print_list(*list);
        }  
    }

}