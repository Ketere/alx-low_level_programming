#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *slow_ptr, *fast_ptr, *temp;
    size_t count = 0;

    if (h == NULL || *h == NULL)
        return 0;

    slow_ptr = *h;
    fast_ptr = *h;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            /* Detected a loop, free nodes before the loop */
            slow_ptr = *h;

            while (slow_ptr != fast_ptr)
            {
                temp = slow_ptr;
                slow_ptr = slow_ptr->next;
                free(temp);
                count++;
            }

            /* Continue freeing nodes within the loop */
            while (slow_ptr->next != fast_ptr)
            {
                temp = slow_ptr;
                slow_ptr = slow_ptr->next;
                free(temp);
                count++;
            }

            /* Free the last node in the loop */
            temp = slow_ptr;
            slow_ptr = slow_ptr->next;
            free(temp);
            count++;

            *h = NULL; /* Set the head to NULL */
            break;
        }
    }

    /* Free any remaining nodes in the list without a loop */
    while (*h != NULL)
    {
        temp = *h;
        *h = (*h)->next;
        free(temp);
        count++;
    }

    return count;
}
