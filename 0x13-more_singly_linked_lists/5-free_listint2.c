#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: A pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
    listint_t *current; // Declare a pointer to traverse the list.

    while (*head != NULL) // Iterate through the list until the end (NULL) is reached.
    {
        current = *head; // Store the current node in 'current'.
        *head = (*head)->next; // Move 'head' to the next node.
        free(current); // Free the memory of the current node.
    }
}
