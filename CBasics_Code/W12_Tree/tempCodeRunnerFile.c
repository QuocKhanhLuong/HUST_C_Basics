#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
    struct Node* parent;
} Node;

Node* makeNode(int u) 
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftMostChild  = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;
}