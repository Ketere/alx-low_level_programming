#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow_ptr, *fast_ptr;
    size_t count = 0;

    slow_ptr = head;
    fast_ptr = head;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
        count++;

        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
            count++;
            break;
        }
    }

    return count;
}
