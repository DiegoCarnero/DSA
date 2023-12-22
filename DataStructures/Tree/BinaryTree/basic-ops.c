#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int height(Node* node){
    if(node == NULL){
        return 0;
    } else {
    // naive / Postorder / DFS
        int rightH = height(node->right);
        int leftH = height(node->left);

        if(rightH > leftH){
            return rightH + 1;
        } else {
            return leftH + 1;
        }
    }
    // implementación de BFS / level order

}


void insert(Node* root, int data){

    if (root == NULL){
        root = createNode(data, NULL, NULL);
    } else {
        /* 
        BFS / level order con cola
        Muchas implementaciones usan dos queues, una con los nodos visitados, 
        pero como en un arbol binario no hay paths circulares esto no es necesario aquí
        */
        Node* queue[9];

        Node* new_node = NULL;
        int front = 0;
        int rear = 0;
        queue[front] = root;

        while(front <= rear) {
            Node* temp = queue[front];
            front++;

            if(temp->left != NULL) {
                rear++;
                queue[rear] = temp->left;
            } else {
                new_node = createNode(data, NULL, NULL);
                temp->left = new_node;
                break;
            }

            if(temp->right != NULL) {
                rear++;
                queue[rear] = temp->right;
            } else {
                new_node = createNode(data, NULL, NULL);
                temp->right = new_node;
                break;
            }
        }
    }
}

Node* insertInorder(Node* node, int data){

    if(node == NULL){
        return createNode(data, NULL, NULL);
    }

    if (data < node->data){
        node->left = insertInorder(node->left, data);
    }
    else{
        node->right = insertInorder(node->right, data);
    }

    return node;
}

Node* parentHelper(Node* node, int data, Node* parent){

    Node * found = NULL;
    if(node == NULL){
        return found;
    }
    if (node->data == data) {
        return parent;
    }
    else {
        found = parentHelper(node->left, data, node);
        if (found == NULL){
            parentHelper(node->right, data, node);
        }
    }
    return found;
}

Node* getParent(Node* root, int data){

    return parentHelper(root, data, NULL);
}

Node* deleteBSTHelper(Node* node, int data, Node* parent){
    
    /*
    El nodo elminado se substituye por sucesor (nodo más pequeño en el subtree derecho)
    o el predecesor (mayor nodo en el subtree izquierdo), idealmente ambos garantizan preservar el
    orden.
    */

    if (parent == NULL){
        Node* r = NULL;
        if(node->left != NULL){
            r = deleteHelper(node->left, data, node);
        } else {
            r = deleteHelper(node->left, data, node);
        }
        return r;
    } else {
        // buscamos el nodo
        if(node->data > data){
            node->left = deleteHelper(node->left, data, parent);
        } else if(node->data < data){
            node->right = deleteHelper(node->right, data, parent);
        } else {    // nodo encontrado
            // tiene un solo hijo
            if (node->left == NULL) {
                Node *temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                Node *temp = node->left;
                free(node);
                return temp;
            }
            // tiene dos hijos, coger el sucesor inorder (numero más pequeño en la rama drch)
            Node* tempParent = node;
            Node* temp = node->right;
            while(temp->left != NULL && temp->right != NULL){
                if(temp->left != NULL){
                    tempParent = temp;
                    temp = temp->left;
                } else {
                    tempParent = temp;
                    temp = temp->right;
                }
            }

            if(parent->data > node->data){
                parent->left = temp;
            } else {
                parent->right = temp;
            }
            temp->left = node->left;
            temp->right = node->right;

            if(tempParent->data > temp->data){
                tempParent->left = NULL;
            } else {
                tempParent->right = NULL;
            }
            free(node);
        }
        return node;
    }
}

Node* delete(Node* node, int data){
    return deleteHelper(node, data, NULL);    
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
    Node* root = NULL;
    /*
    root = createNode(8, NULL, NULL);
    root->left = createNode(3, NULL, NULL);
    root->right = createNode(1, NULL, NULL);
    root->left->left = createNode(6, NULL, NULL);
    root->left->right = createNode(7, NULL, NULL);
    root->right->left = createNode(10, NULL, NULL);
    root->right->right = createNode(7, NULL, NULL);
    */

    int arr[7] = {3,1,6,7,10,14,4};
    root = createNode(8, NULL, NULL);
    for(int i = 0; i < 7; i++){
        insertInorder(root, arr[i]);
    }

    printInorder(root, 0);
    printf("\n");
    /*
    printPreorder(root, 0);
    printf("\n");
    printPostorder(root, 0);

    // char a[10] = {'g','d','i','b','f','h','j','a','c','e'};
    // char a[10] = {'a','b','c','d','e','f','g','h','i','j'};
    root = fromArray(a, 0, 7);
    printf("\nInorder\n");
    printInorder(root, 1);
    printf("\nPreorder\n");
    printPreorder(root, 1);
    printf("\nPostOrder\n");
    printPostorder(root, 1);

    int h = height(root);
    printf("height: %d\n", h);
    
    root->left->left->left = createNode(8, NULL, NULL);
    h = height(root);
    printf("height post insert: %d\n", h);
    insert(root, 0);
    printPostorder(root, 0);
    */

    delete(root, 3);
    printInorder(root, 0);
}