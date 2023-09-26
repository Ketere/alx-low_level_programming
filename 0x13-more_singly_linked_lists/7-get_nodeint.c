#include <stdio.h>
#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head of the list.
 * @index: The index of the node, starting at 0.
 *
 * Return: A pointer to the nth node, or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int count = 0; // Initialize a variable to count nodes.

    while (head != NULL) // Traverse the list.
    {
        if (count == index) // If the current node's index matches the desired index.
        {
            return head; // Return a pointer to the current node.
        }

        head = head->next; // Move to the next node.
        count++; // Increment the node count.
    }

    return NULL; // If the desired index is not found, return NULL.
}
