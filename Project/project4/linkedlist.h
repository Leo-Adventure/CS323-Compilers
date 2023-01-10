
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mips32.h"

struct Node
{
    char *key;
    int offset;
    Register reg;
    struct Node *next;
};

struct Node *initNode();

// insert link at the last location
int insertLast(struct Node *head, char *key);

int findOffset(struct Node *head, char *key);

void insertParam(struct Node *head, char *key, Register reg);

struct Node *findRegister(struct Node *head, char *key);

#endif
