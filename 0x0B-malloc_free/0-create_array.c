#include <stddef.h>
#include <stdlib.h>

/**
 * create_array - creates an array of characters and initializes it with a specific character
 * @size: The size of the array to create
 * @c: The character to initialize the array elements with
 *
 * Return: A pointer to the created array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
    if (size == 0) {
        return (NULL); // Return NULL if size is 0
    }

    char *array = (char *)malloc(sizeof(char) * size);

    if (array == NULL) {
        return (NULL); // Return NULL if memory allocation fails
    }

    for (unsigned int i = 0; i < size; i++) {
        array[i] = c; // Initialize each element with the specified character
    }

    return (array);
}
