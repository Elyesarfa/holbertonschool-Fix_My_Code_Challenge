#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp = *head;
    unsigned int i;

    if (*head == NULL)  // Check if the list is empty
    {
        return (-1);
    }

    // Traverse to the node at index
    for (i = 0; temp != NULL && i < index; i++)
    {
        temp = temp->next;
    }

    // Check if the node to be deleted is out of bounds
    if (temp == NULL)
    {
        return (-1);
    }

    // Node to be deleted is the head node
    if (temp == *head)
    {
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        // Update the prev pointer of the next node
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        // Update the next pointer of the previous node
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
    }

    // Free the memory of the node to be deleted
    free(temp);

    return (1);
}
