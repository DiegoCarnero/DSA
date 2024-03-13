#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* l;
    struct node* r;
    int height;
} Node;

int max(int a, int b){
   return (a > b) ? a : b;
}

int height(Node* node){
    return node ? node->height : -1;
}

void update_height(Node* node) {
    node->height = 1 + max(height(node->l), height(node->r));
}

int getBalance(Node* node) {
    if(node == NULL){
        return 0;
    } else {
        return height(node->l) - height(node->r);
    }
}

Node* rotate_r(Node *node){

    Node* l_child = node->l;
    node->l = l_child->r;
    l_child->r = node;
    
    update_height(node);
    update_height(l_child);

    return l_child;

}

Node* rotate_l(Node *node){

    Node* r_child = node->r;
    node->r = r_child->l;
    r_child->l = node;
    
    update_height(node);
    update_height(r_child);

    return r_child;
}

Node* rebalance(Node* node, int key){
    update_height(node);
    int balance = getBalance(node);
    if(balance > 1){
        if(key < node->l->key){  // Left Left Case  
            node = rotate_r(node);  
        } else if(key > node->l->key){  // Left Right Case
            node->l = rotate_l(node->l);  
            node = rotate_r(node);  
        }
    } else if (balance < -1){
        if(key > node->r->key){  // Right Right Case 
            node = rotate_l(node);  
        } else if(key < node->r->key){  // Right Left Case  
            node->r = rotate_r(node->r);  
            node = rotate_l(node);  
        }
    } 
      
    return node;  

}

Node* new(int key){
    Node* node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->l = NULL;
    node->r = NULL;
    node->height = -1;
    return (node);
}

Node* insert(Node* root, Node* node){

    if(root == NULL){
        root = node;
    } else if (root->key > node->key){   // criterio de comparacion
        root->l = insert(root->l, node);
    }else if (root->key < node->key){    // criterio de comparacion
        root->r = insert(root->r, node);
    }

    root = rebalance(root, node->key);
    return root;
}

// bool delete(Node* root, int key){
    
// }

// Node* search(Node* root, int key){
    
// }

void printInorder(Node* node, int type)
{
    if (node == NULL){
        return;
    }
    printInorder(node->l, type);
    if(type == 0){
        printf("%d ", node->key);
    } else {
        printf("%c ", node->key);
    }
    printInorder(node->r, type);
}

int main(){

    Node* root;
    root = new(1);
    root = insert(root, new(2));
    root = insert(root, new(3));
    root = insert(root, new(6));
    root = insert(root, new(5));
    root = insert(root, new(4));
    printInorder(root, 0);
    printf("\n");

}