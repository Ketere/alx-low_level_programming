#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @idx: The index at which the new node should be inserted (starting at 0).
 * @n: The integer value to add to the new node.
 *
 * Return: The address of the new node, or NULL if it fails.
 * If it is not possible to add the new node at index idx, do not add it and return NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node; // Declare a pointer to the new node.

    if (head == NULL) // Check if the head pointer is NULL (invalid).
        return NULL;

    if (idx == 0) // Special case: Insert at the beginning of the list.
    {
        return add_nodeint(head, n); // Utilize your add_nodeint function for this case.
    }

    listint_t *prev_node = NULL; // Declare a pointer to the previous node.
    listint_t *current = *head; // Declare a pointer to traverse the list.
    unsigned int count = 0; // Initialize a count to keep track of the index.

    while (current != NULL)
    {
        if (count == idx) // If we've reached the desired index.
        {
            new_node = malloc(sizeof(listint_t)); // Allocate memory for the new node.
            if (new_node == NULL) // Check if memory allocation fails.
                return NULL;

            new_node->n = n; // Assign the value 'n' to the data of the new node.
            new_node->next = current; // Make the new node point to the current node.

            if (prev_node != NULL) // If not inserting at the beginning.
                prev_node->next = new_node; // Update the previous node's next pointer.

            return new_node; // Return the address of the new element.
        }

        prev_node = current; // Update the previous node.
        current = current->next; // Move to the next node.
        count++; // Increment the count.
    }

    return NULL; // If the desired index is not found, return NULL.
}
