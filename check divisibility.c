/*En esta tarea trabajará con la lista vinculada de dígitos que hemos creado en las lecciones hasta este punto. Como antes,
se le proporciona un código que no debe modificar:

Una definición de estructura para el almacenamiento de la información de cada dígito.
Una función main() para probar su código. 

Las funciones createDigit(), append(), printNumber(), freeNumber() y readNumber() que hemos escrito en las conferencias.

Su tarea es escribir una nueva función divisibleByThree() que toma como entrada un puntero que contiene la dirección del inicio de una 
lista vinculada de dígitos. Luego, su función debería verificar si el número almacenado en esta lista vinculada de dígitos 
es divisible por tres. La función debería devolver el valor 1 si 
efectivamente el número es divisible por tres y debería devolver el valor 0 en caso contrario. */
#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

// Write your prototypes here
int divisibleByThree(struct digit *start);
struct digit *createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
struct digit *readNumber(void);
void freeNumber(struct digit *start);


int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    freeNumber(start);
    return 0;
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
int divisibleByThree(struct digit *start)
{
    struct digit * ptr = start;

    int sum = 0;

    while (ptr != NULL){
        sum += ptr->num;
        ptr = ptr->next; 
    }
    
        
    if (sum % 3 == 0) {
        return 1; // Es divisible por 3
    } else {
        return 0; // No es divisible por 3
    }


}