#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * free_listint - Frees a listint_t list.
 * @head: A pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
    listint_t *current; // Declare a pointer to traverse the list.

    while (head != NULL) // Iterate through the list until the end (NULL) is reached.
    {
        current = head; // Store the current node in 'current'.
        head = head->next; // Move 'head' to the next node.
        free(current); // Free the memory of the current node.
    }
}
