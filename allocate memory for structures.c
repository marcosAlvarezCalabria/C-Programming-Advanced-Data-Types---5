/*En esta tarea, continuaremos trabajando con polígonos. Se le proporciona lo siguiente:
- Una definición de estructura familiar para un punto bidimensional.
- Dos funciones familiares y sus prototipos, "printPoint()" y "printPoly()".
- Un prototipo de "initializePoly()", una función que debes escribir.
- Una función principal vacía que debes completar.

No modifique el código proporcionado (excepto para completar la función principal y agregar su función inicializePoly()).

inicializePoly() debe recibir como entrada un puntero a la primera estructura en una matriz de estructuras,
así como un número entero, que indica 
cuántos puntos se pueden almacenar en la matriz. Su trabajo es
inicializar estos puntos de la siguiente manera: usando un bucle for con i comenzando en 0,
 inicialice la coordenada x del punto en el índice i como -i y la coordenada y como i*i.

Su función principal debe leer el número de vértices a almacenar en la matriz de puntos del usuario, 
luego asignar la cantidad adecuada de memoria, inicializar la matriz con la función inicializarPoly y
 finalmente imprimir los vértices del polígono usando la función printPoly() .*/
#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {
    int vertices;
    struct point * poligon ;
    
    scanf("%d", &vertices);

    poligon = (struct point *) malloc(vertices *(sizeof (struct point))) ;

    initializePoly(poligon, vertices); 
    
    printPoly( poligon, vertices);

    free(poligon);
    
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

// Write your initializePoly() function here
void initializePoly(struct point * poligon, int vertices)
{
    int i ;

    for (i = 0; i < vertices; i++)
    {
        poligon[i].x -= i;
        poligon[i].y = i * i;        
    }
    

}