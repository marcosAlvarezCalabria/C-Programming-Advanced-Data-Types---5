/*En esta tarea trabajará con la lista vinculada de dígitos que hemos creado en las lecciones hasta este punto. 
Como antes, se le proporciona un código que no debe modificar:

Una definición de estructura para el almacenamiento de la información de cada dígito.
Una función main() para probar su código. 
Las funciones createDigit(), append(), printNumber(), freeNumber(), readNumber() y divisibleByThree() 
(aunque es posible que no necesites usarlas todas).
Su tarea es escribir una nueva función changeThrees() que toma como entrada un puntero que contiene
 la dirección del inicio de una lista vinculada de dígitos. Su función debe cambiar todos los dígitos en esta lista 
 vinculada que equivalen a 3 al dígito 9, 
y contar cuántos reemplazos se realizaron. La función debería devolver este número de reemplazos.*/

#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);
int divisibleByThree(struct digit * start);
struct digit * readNumber(void);
int changeThrees(struct digit *start);
//Add your own function prototypes here

int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("was modified in %d places.\n", changeThrees(start));

    printf("The new number is ");
    printNumber(start);
    freeNumber(start);

    return 0;
}
int changeThrees(struct digit *start)
{
    struct digit * ptr = start;
    int count = 0;

    while (ptr != NULL)
    {
        if(ptr->num == 3)
        {
            ptr->num = 9;
            count ++;
        }
        ptr = ptr->next;
    }
    return count;
}
struct digit * createDigit(int dig) {
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

struct digit * readNumber(void) {
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