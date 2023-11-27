#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int key;
    int value;
    struct node *next;
    struct node *prev;
};
struct arrayitem 
{
    struct node *head;  // primer elemento de la lista en cada indice
    struct node *tail;  // último elemento
};
 
struct arrayitem *array;
int size = 0;
int max = 10;
 
int hashcode(int key)
{
    return (key % max);
}
 
struct node* get_element(struct node *list, int find_index);
void rehash();
int find(struct node *list, int key);
void init_array();
 
void insert(int key, int value)
{
    float load_factor = 0.0; // si hace falta rehashing
    int index = hashcode(key);
    struct node *list = (struct node*) array[index].head;
    struct node *item = (struct node*) malloc(sizeof(struct node));
    item->key = key;
    item->value = value;
    item->next = NULL;
    item->prev = NULL;
    if (list == NULL) {
        printf("\n  %d (key) and %d (value) has been inserted  \n", key, value);
        array[index].head = item;
        array[index].tail = item;
        size++;
    } else {
        int find_index = find(list, key);
        if (find_index == -1) {
            item->prev = array[index].tail;
            array[index].tail->next = item;
            array[index].tail = item;
            size++;
        } else {
            // update value of existing key
            struct node *element = get_element(list, find_index);
            element->value = value;
        }
    }
    load_factor = (1.0 * size) / max;
    if (load_factor >= 0.75) {
        rehash();
    } 
}

void remove_element(int key) {
	int index = hashcode(key);
	struct node *list = (struct node*) array[index].head;
 
	if (list == NULL) {
		printf("\n This key does not exists \n");
 
	} else {
		int find_index = find(list, key);
 
		if (find_index == -1) {
			printf("\n This key does not exists \n");
		} else {
			struct node *temp = list;
			if (temp->key == key) {
				array[index].head = temp->next;
				array[index].head->prev = NULL;
				size--;
				printf("\n This key has been removed \n");
				return;
			}
 
			while (temp->key != key) {
				  temp = temp->next;
			}
 
			if (array[index].tail == temp) {
				temp->prev->next = NULL;
				array[index].tail = temp->prev;
				size--;
			} else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				size--;
			}
			printf("This key has been removed\n");
		}
	}
}
 
/*
Crea una nueva lista con el doble de espacio, e inserta los elementos de la lista original en la neuva
*/
void rehash() {
    struct arrayitem *temp = array;
    int i = 0, n=max;
    size = 0;
    max = 2 * max;
    array = (struct arrayitem*) malloc(size * sizeof(struct node));
    init_array();
    for (i = 0; i < n; i++) {
        struct node* list = (struct node*) temp[i].head;
        if (list == NULL) {
            continue;
        } else {
            while (list != NULL) {
                insert(list->key, list->value);
                list = list->next;
            }
        }
    }
    temp = NULL;
}
 
/*
This function finds the given key in the Linked List
Returns it's index
Returns -1 in case key is not present
*/
int find(struct node *list, int key) {
    int retval = 0;
    struct node *temp = list;
    while (temp != NULL)
        {
        if (temp->key == key)
                {
            return retval;
        }
        temp = temp->next;
        retval++;
    }
    return -1;
}
 
/* Returns the node (Linked list item) located at given find_index */
struct node* get_element(struct node *list, int find_index) {
    int i = 0;
    struct node *temp = list;
    while (i != find_index)
        {
        temp = temp->next;
        i++;
    }
    return temp;
}
void display() {
    int i = 0;
    for (i = 0; i < max; i++) {
        struct node *temp = array[i].head;
        if (temp == NULL) {
            printf("List is empty\n");
        } else {
            printf("array[%d] has elements-: ", i);
            while (temp != NULL) {
                printf("key= %d  value= %d\t", temp->key, temp->value);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
void init_array() {
    int i;
    for (i = 0; i < max; i++) {
        array[i].head = NULL;
        array[i].tail = NULL;
    }
}
int size_of_array()
{
    return size;
}
 
int main() {
    int choice, key, value, n, c;
    array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem));
    init_array();
    do {
        printf("Implementation of Hash Table in C chaining with Doubly Linked List \n\n");
        printf("MENU-: \n1.Inserting item in the Hash Table"
                              "\n2.Removing item from the Hash Table" 
                              "\n3.Check the size of Hash Table" 
                              "\n4.Display a Hash Table"
               "\n\n Please enter your choice-:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Inserting element in Hash Table\n");
                printf("Enter key and value-:\t");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Deleting in Hash Table \n Enter the key to delete-:");
                scanf("%d", &key);
                remove_element(key);
                break;
            case 3:
                n = size_of_array();
                printf("Size of Hash Table is-: %d\n", n);
                break;
            case 4:
                display();
                break;
    
            default:
                printf("Wrong Input\n");
        }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    }while(c == 1);
    getchar();
 
}