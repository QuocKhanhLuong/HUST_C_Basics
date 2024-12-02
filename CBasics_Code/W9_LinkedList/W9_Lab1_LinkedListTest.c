#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int elementtype;

struct node_t
{
    elementtype element;
    struct node_t *next;  // Fixed: using struct node_t instead of struct Node
};

typedef struct node_t Node;
Node *root = NULL;
Node *cur = NULL;
Node *prev = NULL;

Node *makeNewNode(elementtype e)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->element = e;
    new->next = NULL;
    return new;
}

Node *find(Node *root, elementtype e)
{
    Node *p;
    for (p = root; p != NULL; p = p->next)
    {
        if (p->element == e)
            return p;
    }
    return NULL;
}

void insertAtTail(elementtype e)
{
    Node *new = makeNewNode(e);
    if (root == NULL)
    {
        root = new;
        cur = new;
        prev = NULL;
        return;
    }
    Node *p = root;
    while (p->next != NULL)
        p = p->next;
    p->next = new;
    cur = new;
    prev = p;
}

Node *insertLastRecursive(Node *root, elementtype e)
{
    if (root == NULL)
    {
        return makeNewNode(e);
    }
    root->next = insertLastRecursive(root->next, e);
    return root;
}

void insertAtHead(elementtype e)
{
    Node *new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
}

Node *removeNodeRecursive(Node *root, elementtype e)
{
    if (root == NULL)
        return NULL;
    if (root->element == e)
    {
        Node *tmp = root;
        root = root->next;
        free(tmp);
        return root;
    }
    root->next = removeNodeRecursive(root->next, e);
    return root;
}

void freeList()
{
    Node *to_free = root;
    while (to_free != NULL)
    {
        root = root->next;
        free(to_free);
        to_free = root;
    }
}

Node *addBefore(Node *root, elementtype u, elementtype v)
{
    if (root == NULL)
        return NULL;
    if (find(root, u) != NULL)
        return root;  // do nothing
    if (root->element == v)
    {
        Node *q = makeNewNode(u);
        q->next = root;
        return q;
    }
    root->next = addBefore(root->next, u, v);
    return root;
}

Node *addAfter(Node *root, elementtype u, elementtype v)
{
    if (root == NULL)
        return NULL;
    if (root->element == v)
    {
        Node *q = makeNewNode(u);
        q->next = root->next;
        root->next = q;
        return root;
    }
    root->next = addAfter(root->next, u, v);
    return root;
}

Node *reverse(Node *root)
{
    Node *p = root;
    Node *pp = NULL;
    Node *np = NULL;
    while (p != NULL)
    {
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}

void traverseList(Node *root)
{
    Node *p = root;
    while (p != NULL)
    {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}

void solve()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        root = insertLastRecursive(root, k);  // Fixed: using root instead of h
    }
    while (1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;

        if (strcmp(cmd, "addlast") == 0)
        {
            int k;
            scanf("%d", &k);
            if (find(root, k) == NULL)
                insertAtTail(k);
        }
        else if (strcmp(cmd, "addfirst") == 0)
        {
            int k;
            scanf("%d", &k);
            if (find(root, k) == NULL)
                insertAtHead(k);
        }
        else if (strcmp(cmd, "addafter") == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(root, u) == NULL)
                root = addAfter(root, u, v);
        }
        else if (strcmp(cmd, "addbefore") == 0)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(root, u) == NULL)
                root = addBefore(root, u, v);
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            int k;
            scanf("%d", &k);
            root = removeNodeRecursive(root, k);
        }
        else if (strcmp(cmd, "reverse") == 0)
        {
            root = reverse(root);
        }
    }
}

int main()
{
    solve();
    traverseList(root);
    freeList();
}