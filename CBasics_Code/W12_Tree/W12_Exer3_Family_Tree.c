#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
#define MAX_NODES 100 

typedef struct Node{
    char name[MAX_LEN];
    struct Node* leftMostChild;
    struct Node* rightSibling;
    struct Node* parent;
}Node;

Node* nodes[MAX_NODES];  
int n;  

Node* makeNode(const char* name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;
}

Node* findNode(char* name){
    for(int i = 0; i < n; i++){
        if(strcmp(nodes[i]->name,name) == 0){
            return nodes[i];
        }
    }
    return NULL;
}

void addChild(Node* child, Node* parent){
    child->parent = parent;
    if(parent->leftMostChild == NULL){
        parent->leftMostChild = child;
    }else{
        Node* p = parent->leftMostChild;
        while(p->rightSibling != NULL)
            p = p->rightSibling;
        p->rightSibling = child;
    }
}

int height(Node* nod){
    if(nod == NULL) return 0;
    int maxH = 0;
    Node* p = nod->leftMostChild;
    while(p != NULL){
        int h = height(p);
        if(h > maxH) maxH = h;
        p = p->rightSibling;
    }
    return maxH + 1;
}

int countNodes(Node* nod){
    if(nod == NULL) return 0;
    Node* p = nod->leftMostChild;
    int cnt = 1;
    while(p != NULL){
        cnt += countNodes(p);
        p = p->rightSibling;
    }
    return cnt;
}

void solve(){
    while(1){
        char name1[MAX_LEN], name2[MAX_LEN];
        scanf("%s",name1); if(strcmp(name1,"***")== 0) break;
        scanf("%s",name2);
        Node* n1 = findNode(name1);
        if(n1 == NULL){
            n++; 
            nodes[n-1] = makeNode(name1); 
            n1 =nodes[n-1]; 
        }
        Node* n2 = findNode(name2);
        if(n2 == NULL){
            n++; 
            nodes[n-1] = makeNode(name2); 
            n2 =nodes[n-1];}
        addChild(n1,n2);
    }
    while(1){
        char cmd[MAX_LEN]; 
        scanf("%s",cmd);
        if(strcmp(cmd,"***")==0) break;
        if(strcmp(cmd,"descendants")==0){
            char param[MAX_LEN];
            scanf("%s",param);
            Node* nod = findNode(param);
            int ans = countNodes(nod);
            printf("%d\n",ans-1);
        }else if(strcmp(cmd,"generation")==0){
            char param[MAX_LEN];
            scanf("%s",param);
            Node* nod = findNode(param);
            int ans = height(nod);
            printf("%d\n",ans-1); 
        }
    }
}

int main(){
    n = 0;
    solve();
    return 0;
}