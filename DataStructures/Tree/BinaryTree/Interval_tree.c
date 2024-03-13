#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Pair {
    int low;
    int high;
};

typedef struct node {
    struct Pair* p;
    int max;
    struct node* l;
    struct node* r;
} Node;

Node* new(int low, int high){
    Node* node = (Node *) malloc(sizeof(Node));
    node->p = (struct Pair*) malloc(sizeof(struct Pair));
    node->p->low = low;
    node->p->high = high;
    return node;
}

Node* insert(Node* root, Node* node){
    
    if(root == NULL){
        root = node;
    } else if (root->p->low < node->p->low){
        root->r = insert(root->r, node);
    } else if (root->p->low > node->p->low){
        root->l = insert(root->l, node);
    }

    if(root->max < node->max){
        root->max = node->max;
    }

    return root;
}

bool Overlap(struct Pair* intrv1, struct Pair* intrv2){
    return !(intrv1->high < intrv2->low || intrv2->high < intrv1->low);
}

Node* intersecSearch(Node* root, struct Pair* intrv){

    Node* ret = NULL;

    if (Overlap(root->p, intrv)){
        ret = root;
    } else if (root->r != NULL && root->r->max <= intrv->high){
        ret = intersecSearch(root->r, intrv);
    } else if(root->l != NULL){
        ret = intersecSearch(root->l, intrv);
    }

    return ret;
}

int main(){


    Node* root = new(17, 19);
    root = insert(root, root);
    root = insert(root, new(5, 8));
    root = insert(root, new(4, 8));
    root = insert(root, new(15, 18));
    root = insert(root, new(7, 10));
    root = insert(root, new(16, 22));
    root = insert(root, new(21, 24));

    struct Pair intrvs[] = { { 23, 25 }, { 12, 14 }, { 21, 23 } };

    for(int i = 0; i < 3; i++){
        printf("{%d, %d}:%s\n", intrvs[i].low, intrvs[i].high, intersecSearch(root, &intrvs[i]) ? "true" : "false");
    }

    // struct Pair* p1 = (struct Pair*) malloc(sizeof(struct Pair));
    // struct Pair* p2 = (struct Pair*) malloc(sizeof(struct Pair));
    // struct Pair* p3 = (struct Pair*) malloc(sizeof(struct Pair));
    // struct Pair* p4 = (struct Pair*) malloc(sizeof(struct Pair));

    // p1->low = 1;
    // p1->high = 4;

    // p2->low = 3;
    // p2->high = 5;

    // p3->low = 0;
    // p3->high = 2;

    // p4->low = -1;
    // p4->high = 1;

    // printf("%s\n", Overlap(p1, p2) ? "true" : "false");
    // printf("%s\n", Overlap(p1, p3) ? "true" : "false");
    // printf("%s\n", Overlap(p1, p4) ? "true" : "false");
    // printf("%s\n", Overlap(p2, p3) ? "true" : "false");
}