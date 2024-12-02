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

Node* find(Node* r, int u){
    if(r == NULL) return NULL;
    if(r->id == u) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* q = find(p,u);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

void insert(Node* r, int u, int v){
    Node* p = find(r, v);
    if (p == NULL) return;
    Node* q = makeNode(u);
    if(p->leftMostChild == NULL) {
        p->leftMostChild = q;
        q->parent = p;
        return;
    }
    Node* h = p->leftMostChild;
    while(h->rightSibling != NULL)
        h = h->rightSibling;
    h->rightSibling = q;
    q->parent = p;
}

void preOrder(Node* r){
    if(r == NULL) return;
    printf("%d ", r->id);
    Node* p = r->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    if(p != NULL) 
        inOrder(p);
    printf("%d ", r->id);
    while(p != NULL){
        p = p->rightSibling;
        if(p != NULL)  
            inOrder(p);
    }
}

void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->id);
}

void freeTree(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* np = p->rightSibling;
        freeTree(p);
        p = np;
    }
    free(r);
}

void solve() {
    Node* root = NULL;
    char cmd[50];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"*") == 0) {
            break;
        } else if(strcmp(cmd,"MakeRoot") == 0){
            int id;
            scanf("%d", &id);
            root = makeNode(id);
        } else if(strcmp(cmd,"Insert") == 0){
            int u,v;
            scanf("%d%d", &u, &v);
            insert(root,u,v);
        } else if(strcmp(cmd,"PreOrder") == 0){
            preOrder(root);
            printf("\n");
        } else if(strcmp(cmd,"InOrder") == 0){
            inOrder(root);
            printf("\n");
        } else if(strcmp(cmd,"PostOrder") == 0){
            postOrder(root);
            printf("\n");
        }
    }
    freeTree(root);
}

int main(){
    solve();
    return 0;
}