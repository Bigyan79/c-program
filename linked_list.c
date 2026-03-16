#include <stdio.h>
#include <stdlib.h>

// Defining Node Structure
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Creating Nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocating Memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    if (!head || !second || !third)
    {
        printf("Memory allocation has been failed\n");
        return 1;
    }

    // Assigning Data and address for next node
    head->data = 10;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 20;
    third->next = NULL;

    // Printing Output
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("Null \n");

    // Freeing allocated Memory
    temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}