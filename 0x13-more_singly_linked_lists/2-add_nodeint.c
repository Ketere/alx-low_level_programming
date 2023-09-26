#include <stdio.h>
#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The integer value to add to the new node.
 *
 * Return: The address of the new element, or NULL if it fails (memory allocation error).
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node; // Declare a pointer to the new node.

    new_node = malloc(sizeof(listint_t)); // Allocate memory for the new node.
    if (new_node == NULL) // Check if memory allocation failed.
    {
        return (NULL); // Return NULL if memory allocation fails.
    }

    new_node->n = n; // Assign the value 'n' to the data of the new node.
    new_node->next = *head; // Make the new node point to the current head.

    *head = new_node; // Update the head to point to the new node.

    return (new_node); // Return the address of the new element.
}
