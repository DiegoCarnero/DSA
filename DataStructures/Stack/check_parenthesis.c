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

bool match(char opening, char closing){
    
    if ((opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']') ){
        return true;
    } else {
        return false;
    }
}

bool isBalanced(char arr[]){

    int len =  strlen(arr);
    Stack* stack = initStack(len / 2);
    char popped;
    for(int i = 0; i < len; i++){
        if((arr[i] == '(') || (arr[i] == '{') || (arr[i] == '[')){
            push(stack, arr[i]);
        } else if((arr[i] == ')') || (arr[i] == '}') || (arr[i] == ']')){
            popped = pop(stack);
            if (!match(popped, arr[i])){
                return false;
            }
        }
    }
    return true;
}

int main(){
    char arr[] = "({[()()]})";
    printf("%d", isBalanced(arr));
}
