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

int depth(Node* r)
{
    Node* p = r;
    int d = 0;
    while(p != NULL){
        d+=1;
        p = p->parent;
    }
    return d;
}

int height(Node* r)
{
    int maxH = 0;
    if(r == NULL) 
        return 0;
    for(Node* p = r->leftMostChild; p != NULL; p = p->rightSibling) {
        int h = height(p);
        if(h >maxH)    
            maxH = h;
    }
    return maxH + 1;
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
        } else if(strcmp(cmd,"Height") == 0){
            int id;
            scanf("%d", &id);
            Node* p = find(root, id);
            printf("%d\n", height(p));
        } else if(strcmp(cmd,"Depth") == 0){
            int id;
            scanf("%d",&id);
            Node* p = find(root, id);
            int d = depth(p);
            printf("%d\n", d);
        }
    }
    freeTree(root);
}

int main(){
    solve();
}
