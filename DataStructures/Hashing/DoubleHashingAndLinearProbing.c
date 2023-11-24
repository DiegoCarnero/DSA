#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
    
struct data {
    int key;
    int value;
};
    
struct hashtable_item  {    
    int flag; //0 : data not present, 1 : some data already present, 2 : data was present,but deleted
    struct data *item;    
};
    
struct hashtable_item *array;
int max = 10;
int size = 0;
int prime = 7; // primo menor que max más proximo
    
int hashcode1(int key) {
    return (key % max);
}
    
int hashcode2(int key) {
    return (prime - (key % prime));
}
    
/* returns largest prime number less than size of array */
int get_prime() {
    int i,j;
    for (i = max - 1; i >= 1; i--)
        {
        int flag = 0;
        for (j = 2; j <= (int)sqrt(i); j++)
                {
            if (i % j == 0)
                        {
                flag++;
            }
        }
        if (flag == 0)
                {
            return i;
        }
    }
    return 3;
    
}
    
void insert(int key, int value) {
    int probe = hashcode1(key);
    int offset = hashcode2(key);
    
    int index = probe;
    
    /* create new data to insert */
    struct data *new_item = (struct data*) malloc(sizeof(struct data));
    new_item->key = key;
    new_item->value = value;
    
    if (size == max) 
        {
        printf("\n Hash Table is full, cannot insert more items \n");
        return;
    }
    
    /* probing through other array elements */
    while (array[index].flag == 1) {
        if (array[index].item->key == key)
                {
            printf("\n Key already present, hence updating its value \n");
            array[index].item->value = value;
            return;
        }
        index = (index + offset) % max; 
        if (index == probe)
                {
            printf("\n Add is failed \n");
            return;
        }
        printf("\n probing \n");
    
    }
    
    array[index].item = new_item;
    array[index].flag = 1;
    size++;
    printf("\n Key (%d) has been inserted \n", key);
    
}
    
/* to remove an element from the array */
void remove_element(int key) {
    int probe = hashcode1(key);
    int offset = hashcode2(key);
    int index = probe;
    
    if (size == 0)
        {
        printf("\n Hash Table is empty \n");
        return;
    }
    
    /* probing through other elements */
    while (array[index].flag != 0)
        {
        if (array[index].flag == 1  &&  array[index].item->key == key)
                {
            array[index].item = NULL;
            array[index].flag = 2;
            size--;
            printf("\n Key (%d) has been removed \n", key);
            return;
        }
        index = (index + offset) % max;
        if (index == probe)
                {
            break;
        }
    }
    
    printf("\n Key (%d) does not exist \n", key);   
}

struct data* search(int value){
    int probe = hashcode1(value), offset = hashcode2(value);
    int index = probe;
    
    while (array[index].flag != 0) {
        if (array[index].flag == 1  &&  array[index].item->key == value) {
            return array[index].item;
        }
        index = (index + offset) % max;
        if (index == probe) {
            break;
        }
    }
    return NULL;
}
    
int size_of_hashtable() {
    return size;
}
    
/* displays all elements of array */
void display() {
    int i;
    for (i = 0; i < max; i++)
        {
        if (array[i].flag != 1)
                {
            printf("\n Array[%d] has no elements \n", i);
        }
        else
                {
            printf("\n Array[%d] has elements \n Key (%d) and Value (%d) \n", i, array[i].item->key, array[i].item->value);
        }
    }
}
    
/* initializes array */
void init_array() {
    int i;
    for(i = 0; i < max; i++)
        {
        array[i].item = NULL;
        array[i].flag = 0;
    }
    prime = get_prime();
}
    
int main() {
    int choice, key, value, n, c;
    struct data* search_ret;
    
    array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
    init_array();
    
    do {
        printf("Implementation of Hash Table in C with Double Hashing.\n\n");
        printf("MENU-: \n1.Inserting item in the Hash Table" 
                                "\n2.Removing item from the Hash Table" 
                                "\n3.Check the size of Hash Table" 
                                "\n4.Search in table"
                                "\n5.Display Hash Table"
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
                    n = size_of_hashtable();
                    printf("Size of Hash Table is-:%d\n", n);
                    break;
            case 4:
                    printf("Enter key to search:");
                    scanf("%d", &key);
                    search_ret = search(key);
                    if(search_ret){
                        printf("Key %d in table: %d\n", key, (search_ret->value));
                    } else {
                        printf("Not found\n");
                    }
                    break;
            case 5:
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