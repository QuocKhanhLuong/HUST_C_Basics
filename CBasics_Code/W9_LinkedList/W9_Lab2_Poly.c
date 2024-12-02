#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 10001

typedef struct TNode
{
    int coef;
    int exp;
    struct TNode *next;
} Node;

Node *P[N]; // P[i] is the pointer to the first element of linked list representing the polynomial id = i

Node *makeNode(int c, int e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->coef = c;
    p->exp = e;
    p->next = NULL;
    return p;
}

void printPoly(Node *p)
{
    for (Node *q = p; q != NULL; q = q->next)
    {
        printf("%d %d ", q->coef, q->exp);
        printf("\n");
    }
    printf("\n");
}

Node *addTerm(int c, int e, Node *p)
{
    if (p == NULL)
        return makeNode(c, e);
    if (e > p->exp)
    {
        Node *q = makeNode(c, e);
        q->next = p;
        return q;
    }
    if (e == p->exp)
    {
        p->coef += c;
        return p;
    }
    p->next = addTerm(c, e, p->next);
    return p;
}
void processAddTerm(int id, int c, int e) 
{
    P[id] = addTerm(c,e,P[id]);
}

Node *addPoly(Node *p1, Node *p2)
{
    Node *prs = NULL;
    Node *last = prs;
    // copy poly p1 to prs
    for (Node *q = p1; q != NULL; q = q->next)
    {
        Node *newNode = makeNode(q->coef, q->exp);
        if (prs == NULL)
            prs = newNode;
        else
            last->next = newNode;
        last = newNode;
    }
    for (Node *q = p2; q != NULL; q = q->next)
    {
        prs = addTerm(q->coef, q->exp, prs);
    }
    return prs;
}

void processAddPoly(int id1, int id2, int idrs)
{
    P[idrs] = addPoly(P[id1], P[id2]);
}

void processEvaluatePoly(int id, int x)
{
    long long rs = 0;
    for (Node *q = P[id]; q != NULL; q = q->next)
    {
        rs = rs + q->coef * pow(x, q->exp);
    }
    printf("%lld", rs);
}

int main()
{
    char cmd[50];
    for (int id = 1; id <= N - 1; id++)
        P[id] = NULL;

    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0)
            break;
        else if (strcmp(cmd, "AddTerm") == 0)
        {
            int id, c, e;
            scanf("%d%d%d", &id, &c, &e);
            processAddTerm(id, c, e);
        }
        else if (strcmp(cmd, "PrintPoly") == 0)
        {
            int id;
            scanf("%d", &id);
            printPoly(P[id]);
        }
        else if (strcmp(cmd, "AddPoly") == 0)
        {
            int id1, id2, idrs;
            scanf("%d%d%d", &id1, &id2, &idrs);
            processAddPoly(id1, id2, idrs);
        }
        else if (strcmp(cmd, "EvaluatePoly") == 0)
        {
            int id, x;
            scanf("%d%d", &id, &x);
            processEvaluatePoly(id, x);
        }
    }
    return 0;
}