/*En esta tarea, volverá a trabajar con la lista vinculada de dígitos que creamos durante las lecciones hasta este punto. 

Se le proporcionan (pero no está obligado a utilizar) las funciones y prototipos que hemos escrito hasta ahora. 
También se le proporciona una función main() para probar su código. No modifique esta función main().

Su tarea es escribir una nueva función countRedun() que toma como entrada un puntero que contiene la dirección del
 inicio de una lista vinculada 
de dígitos. Su función debe contar cuántas redundancias se pueden observar en el número almacenado en esta lista y 
devolver este recuento de redundancias. Una redundancia es un dígito que ya apareció anteriormente en el número.
 Por ejemplo, en el número 39534, el segundo '3' es una redundancia.*/
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here
int countRedun(struct digit *start);
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);


// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}
int countRedun(struct digit *start) {
    struct digit *ptr = start;
    int numChecked;
    int counterRedun = 0;

    while (ptr != NULL && ptr->next != NULL) { // Asegurarse de que ptr->next no sea NULL
        numChecked = ptr->num;
        if (numChecked == ptr->next->num) { // Contar solo si son iguales
            counterRedun++;
        }
        ptr = ptr->next;
    }

    return counterRedun;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}