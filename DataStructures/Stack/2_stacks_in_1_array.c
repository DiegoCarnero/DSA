#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 10

int stack[SIZE]; 
int top1 = -1; 
int top2 = SIZE; 

bool isFull(){
    return (top1 == (top2 -1));
}

bool PushStack1(int data) {
    int ret;
    if (!(isFull())) { 
        stack[++top1] = data;
        ret = true;
    } 
    else { 
        printf("Stack full\n"); 
        ret = false;
    }
    return ret;
}

bool PushStack2(int data) {
    int ret;
    if (!(isFull())) { 
        stack[--top2] = data;
        ret = true;
    } 
    else { 
        printf("Stack full\n"); 
        ret = false;
    }
    return ret;
}

int PopStack1() {
    int popped_value;
    if (top1 >= 0) { 
        popped_value = stack[top1--]; 
    } 
    else { 
        printf("Stack Empty\n");
        exit(1);
    }
    return popped_value;
}

int PopStack2() {
    int popped_value;
    if (top2 < SIZE) { 
        popped_value = stack[top2++];
    } else { 
        printf("Stack Empty\n");
        exit(1);
    }
    return popped_value;
} 

void PrintStack1() { 
    int i;
    for (i = top1; i >= 0; i--) 
    { 
        printf("%d ", stack[i]); 
    } 
    printf("\n"); 
}

void PrintStack2() { 
    int i;
    for (i = top2; i < SIZE; i++) 
    { 
        printf("%d ", stack[i]); 
    } 
    printf("\n"); 
}
int main() 
{
    int i;

    for (i = 1; i <= 6; ++i) 
    { 
        PushStack1 (i);
    }

    for (i = 1; i <= 4; ++i) 
    { 
        PushStack2 (i);
    }

    printf("Popped from stack1: %d\n", PopStack1());
    printf("Popped from stack2: %d\n", PopStack2());

    PrintStack1(); 
    PrintStack2();

    PushStack1(6);
    printf("Pushing Value in Stack 1 is %d\n", 11); 
    PushStack1(11); 

    int num = top1 + 1;
    while (num) 
    { 
        PopStack1 (); 
        num--; 
    }
    PopStack1 ();

    return 0; 
}