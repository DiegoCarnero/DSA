#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int compare_abs(const void* a, const void* b){
    int A = *((int*)a);
    int B = *((int*)b);
    return abs(A)-abs(B); // si positivo, A es mayor, si negativo, B es mayor
}

void Increment(int a){
    a = a + 1;
}

void IncrementByReference(int *p){
    *p = (*p) + 1;
}

int SumOfElements(int A[], int size){
    int i, sum = 0;

    for (i=0; i < size; i++){
        sum += A[i];
    }

    return sum;
}

void DoubleInPlace(int A[], int size){
    
    for (int i=0; i < size; i++){
        A[i] = 2 * A[i];
    }

}

// const para que no se pueda modificar
void print(const char *C){
    while(*C != '\0'){
        printf("%c", *C);
        C++;
    }
    printf("\n");
}
/*        //    A[][2][2]
int Func(int (*A)[2][2]){

}
*/

int *Add(int* a, int* b){
    /*
    int c = (*a) + (*b);
    return &c;
    */
    int* c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b);
    return c;
}

void PrintHelloWorld(){
    printf("HelloWorld\n");
}

void callbackTest(void (*ptr)()){
    ptr();
}

int main(){
    /*
    int z;
    int *y;
    y = &z;
    printf("sin inicializar: %d\n", *y);
    *y = 13;
    printf("%d = %d\n", y, &z);
    printf("&y: %d\n", &y);
    printf("*y: %d\n", *y);
    *y = 14;
    printf("*y: %d\n\n", *y);

    char a;
    char *b;
    char **c;

    a = 'Z';
    b = "aqwer"; // read as "address of a"
    c = &b; // read as "address of b"
    printf("a): %c\n", a);
    printf("*b: %d\n", *b);
    printf("b: %s\n", b);
    printf("*c: %s\n", *c);

    *c = "poui";
    printf("*c: %s\n", *c);

    int x = 5;
    int* p = &x;
    *p = 6;
    int** q = &p;
    int*** r = &q;
    printf("*p: %d\n", *p);
    printf("*q: %d\n", *q);
    printf("**q: %d\n", **q);
    printf("**r: %d\n", **r);
    printf("***r: %d\n", ***r);
    ***r = 10;
    printf("x = %d\n", x);
    **q = *p + 3;
    printf("x: %d\n", x);
    */

    int a;  // goes to the stack
    a = 10;
    IncrementByReference(&a);
    printf("a = %d\n", a);

    /*
    address - &A[i] or (A + i)
    value - A[i] or *(A + i)
    base - A or &A[0]

    int *p = A;
    A++; // invalid
    p++; // valid
    */

    int A[] = {1,2,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);
    int total;
    total = SumOfElements(A, size);
    printf("sum: %d\n", total);

    // DoubleInPlace(A, size);
    // print array

    char c[6] = {'d','i','e','g','o','\0'};
    // char c[];
    // c = "diego"; no se puede
    int len = strlen(c);
    /*
    char C[20] = "Hello"; // string almacenado en stack, igual que pasarselo a printf
    char *C = "Hello"; // almacenado como constante al compilar
    C[0] = 'A' //no se pué
    */
    /*
    int B[2][3];
    int (*p)[3] = B;

    address - *B or B[0] or &B[0][0]
    address segunda file - B + 1 or &B[1] or *(B+1) or B[1] or &B[1][0]
    *(B + 1) + 2 or B[1] + 2 or &B[1][2]
    B[i][j] = *(B[i] + j) = *(*(B + i) + j)

    *(*B + 1): B -> int (*) [3]
               *B = B[0] -> int *
               *B+1 = &B[0][1]
               *(*B+1) = B[0][1]
    */
/*/
    int C[3][2][2] = {{{2,5},{7,9},{3,4},{6,1},{0,8},{11,13}}};
    int (*t)[2][2] = C;
    // c[i][j][k] = *(c[i][j]+k) = *(*(c[i]+j)+k) = *(*(*(c+i)+j)+k)
    printf("%d %d %d %d", C, *C, C[0], &C[0][0]);
*/
    int *p;
    p = (int *)malloc(sizeof(int)); // goes to the heap (system memory). En C++: p = new int;
    *p = 10;
    free(p);                                                     //      En C++: delete p;
    p = (int*)malloc(20 *sizeof(int));                           //      En C++: p = new int[20];
                                                                 //              delete[] p;

    /*
                            v- unsigned int
    malloc - void* malloc(size_t size)
            no puedes asignar valor a un  void *. Hay que castearlo a un tipo
    calloc - void * calloc(size_t num, size_t, size)
            calloc pone todas las direcciones de memoria asignadas a cero, malloc no
    realloc - void * realloc(void* existing_block_ptr, size_t new_block_size)
            si hay espacio despues del bloque ya existente, lo extiende

    */
    /*
    int n;
    printf("\n\nSize of array: ");
    scanf("%d", &n);
    int *Arr = (int*) calloc(n, sizeof(int));

    // memoria dinámica vive hasta que termine el programa a menos que la liberemos a mano
    free(Arr);
    // A = NULL;
    // dependiendo del compilador y la máquina, podremos acceder e incluso modificar memoria depués de liberarla a través del puntero.
    Arr[2] = 6;
    for(int i = 0; i<n; i++){
        printf("%d ", Arr[i]);
    }

    printf("\n");

    int *B = (int*) realloc(Arr, (n/2)*sizeof(int));
    printf("Addr of A: %d - Addr of B: %d\n", A, B);
    // int *B = (int*)realloc(A,0); // equivalente a free(A)
    // int *B = (int*)realloc(NULL, n*sizeof(int)); // equivalentea malloc

    int d = 2, e = 4;
    int* ptr = Add(&d, &e);
    PrintHelloWorld();
    printf("Sum = %d", *ptr);


    int c;
    int (*p)(int,int);  // funcion que retorna puntero a int: int *p(int,int);
    p = Add;   // &Add tambien vale
    // c = (*p)(2,3); // tambien vale p(2,3);
    printf("%d", c)
*/
    callbackTest(PrintHelloWorld);

    int i, ArrSigned[] = {-31, 22, -1, 50, -6, 4};
    qsort(ArrSigned, 6, sizeof(int), compare_abs);
    for(i = 0; i<6; i++) printf("%d ", ArrSigned[i]);
}

