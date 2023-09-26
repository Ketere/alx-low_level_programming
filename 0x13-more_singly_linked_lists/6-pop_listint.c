#include <stdlib.h>
#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: The data (n) of the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    int data = 0; // Initialize data to 0.

    if (*head != NULL) // Check if the list is not empty.
    {
        listint_t *temp = *head; // Create a temporary pointer to the current head.
        data = temp->n; // Get the data (n) of the current head node.
        *head = (*head)->next; // Update the head to point to the next node.
        free(temp); // Free the memory of the previous head node.
    }

    return data; // Return the data (n) of the deleted head node (or 0 if the list was empty).
}
