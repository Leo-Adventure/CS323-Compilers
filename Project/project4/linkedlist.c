#include <stdbool.h>
#include "linkedlist.h"

struct Node *initNode()
{
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
    link->next = NULL;
    link->key = NULL;
    link->offset = -1;
    link->reg = not_exist;
    return link;
}

// insert link at the last location
int insertLast(struct Node *head, char *key)
{
    // create a link
    struct Node *link = initNode();
    link->key = key;
    int data = 0;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp != head)
    {
        data = temp->offset + 4;
    }
    temp->next = link;
    link->offset = data;
    return data;
}

void insertParam(struct Node *head, char *key, Register reg)
{
    // create a link
    struct Node *link = initNode();
    link->key = key;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = link;
    link->reg = reg;
}

struct Node *findRegister(struct Node *head, char *key)
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (strcmp(temp->key, key) == 0)
        {
            return temp;
        }
    }
    return NULL;
}

int findOffset(struct Node *head, char *key)
{
    // create a link
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (strcmp(temp->key, key) == 0)
        {
            return temp->offset;
        }
    }
    return -1;
}