#include "lists.h" // Include your header file that contains the listint_t structure.

/**
 * sum_listint - Returns the sum of all the data (n) in a listint_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: The sum of all the data (n) in the list, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
    int sum = 0; // Initialize a variable to store the sum.

    while (head != NULL) // Traverse the list.
    {
        sum += head->n; // Add the data (n) of the current node to the sum.
        head = head->next; // Move to the next node.
    }

    return sum; // Return the calculated sum.
}
