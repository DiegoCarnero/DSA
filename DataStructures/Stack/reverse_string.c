#include <limits.h> // establece valores maximos de varios tipos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack {
    int top;
    int capacity;
    char* arr;
} Stack;

Stack* initStack(int capacity){

    Stack* stack = malloc(sizeof(Stack));
    stack->arr = (char*) malloc(capacity * sizeof(char));
    stack->capacity = capacity;
    stack->top = -1;

    return stack;
}

bool push(Stack* stack, char c){
    bool ret = false;
    if(stack->top < stack->capacity){
        stack->top++;
        stack->arr[stack->top] = c;
        ret = true;
    }
    return ret;
}

char pop(Stack* stack){

    char c;
    if(stack->top > -1){
        c = stack->arr[stack->top];
        stack->arr[stack->top] = 0;
        stack->top--;
    }
    return c;

}

void printStack(Stack* stack){

    printf("%s\n", stack->arr);

}

void reverse(char arr[]){

    int len = strlen(arr);
    Stack* stack = initStack(len);
    int i;
    for(i = 0; i < len;i++){
        push(stack, arr[i]);
    }
    for(i = 0; i < len;i++){
        arr[i] = pop(stack);
    }

}

int main(){

    // Stack* stack = initStack(10);
    // push(stack, 'D');
    // push(stack, 'i');
    // push(stack, 'e');
    // push(stack, 'g');
    // push(stack, 'o');
    // printStack(stack);
    // pop(stack);
    // printStack(stack);
    char arr[] = "Esto es un string";
    reverse(arr);
    printf("%s\n", arr);

}