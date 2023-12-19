#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* createNode(int data, Node* l, Node* r)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = l;
    node->right = r;
 
    return node;
}

void printInorder(struct Node* node, int type)
{
    if (node == NULL){
        return;
    }
    printInorder(node->left, type);
    if(type == 0){
        printf("%d ", node->data);
    } else {
        printf("%c ", node->data);
    }
    printInorder(node->right, type);
}

void printPostorder(struct Node* node, int type)
{
    if (node == NULL){
        return;
    }

    printPostorder(node->left, type);
    printPostorder(node->right, type);
    if(type == 0){
        printf("%d ", node->data);
    } else {
        printf("%c ", node->data);
    }
}

void printPreorder(struct Node* node, int type)
{
    if (node == NULL){
        return;
    }

    if(type == 0){
        printf("%d ", node->data);
    } else {
        printf("%c ", node->data);
    }
    printPreorder(node->left, type);
    printPreorder(node->right, type);
}

Node* fromArray(char arr[], int ndx, int size){

    if (ndx >= size){
        return NULL;
    } else {
        return(createNode(arr[ndx],
                fromArray(arr, 2 * ndx + 1, size),
                fromArray(arr, 2 * ndx + 2, size)));
    }
}

int main()
{
    Node* root = createNode(1, NULL, NULL);
    root->left = createNode(2, NULL, NULL);
    root->right = createNode(3, NULL, NULL);
    root->left->left = createNode(4, NULL, NULL);
    root->left->right = createNode(5, NULL, NULL);
    root->right->left = createNode(6, NULL, NULL);
    root->right->right = createNode(7, NULL, NULL);

    printInorder(root, 0);
    
    char a[10] = {'g','d','i','b','f','h','j','a','c','e'};
    // char a[10] = {'a','b','c','d','e','f','g','h','i','j'};
    root = fromArray(a, 0, 10);
    printf("\nInorder\n");
    printInorder(root, 1);
    printf("\nPreorder\n");
    printPreorder(root, 1);
    printf("\nPostOrder\n");
    printPostorder(root, 1);
    return 0;
}