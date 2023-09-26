#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * delete_nodeint_at_index - Deletes the node at a given index in a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted (starting at 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    if (head == NULL || *head == NULL) // Check if the head pointer or the list is empty.
        return -1;

    if (index == 0) // Special case: Delete the head node.
    {
        listint_t *temp = *head; // Create a temporary pointer to the head.
        *head = (*head)->next; // Update the head to point to the next node.
        free(temp); // Free the memory of the previous head node.
        return 1; // Return 1 to indicate success.
    }

    listint_t *prev_node = NULL; // Declare a pointer to the previous node.
    listint_t *current = *head; // Declare a pointer to traverse the list.
    unsigned int count = 0; // Initialize a count to keep track of the index.

    while (current != NULL)
    {
        if (count == index) // If we've reached the desired index.
        {
            if (prev_node != NULL) // If not deleting the head node.
                prev_node->next = current->next; // Update the previous node's next pointer.

            free(current); // Free the memory of the current node.
            return 1; // Return 1 to indicate success.
        }

        prev_node = current; // Update the previous node.
        current = current->next; // Move to the next node.
        count++; // Increment the count.
    }

    return -1; // If the desired index is not found, return -1 (failure).
}
