#include <stdio.h>
#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The integer value to add to the new node.
 *
 * Return: The address of the new element, or NULL if it fails (memory allocation error).
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node; // Declare a pointer to the new node.
    listint_t *temp = *head; // Create a temporary pointer to traverse the list.

    new_node = malloc(sizeof(listint_t)); // Allocate memory for the new node.
    if (new_node == NULL) // Check if memory allocation failed.
    {
        return (NULL); // Return NULL if memory allocation fails.
    }

    new_node->n = n; // Assign the value 'n' to the data of the new node.
    new_node->next = NULL; // Set the next pointer of the new node to NULL.

    if (*head == NULL) // If the list is empty, make the new node the head.
    {
        *head = new_node;
    }
    else
    {
        while (temp->next != NULL) // Traverse the list to find the last node.
        {
            temp = temp->next;
        }

        temp->next = new_node; // Make the last node point to the new node.
    }

    return (new_node); // Return the address of the new element.
}
