#include <stddef.h> // Include this header for size_t
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
    size_t node_count = 0; // Initialize a variable to count nodes.

    while (h != NULL) // Iterate through the list until the end (NULL) is reached.
    {
        node_count++; // Increment the node count.
        h = h->next; // Move to the next node.
    }

    return node_count; // Return the total number of nodes.
}
