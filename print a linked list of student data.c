/*En esta tarea continuarás trabajando en la lista vinculada de estudiantes en la que te gustaría almacenar, 
para cada estudiante, su nombre y edad. Como antes, se le proporciona un código que no debe modificar:

Definición de una estructura para el almacenamiento de la información de cada estudiante.
Una función main() para probar su código. 
Prototipos para las funciones createStudent(), append() (de tareas anteriores) y printStudents() 
(de la tarea actual).
Necesitará las definiciones de funciones (de tareas anteriores) para createStudent(), 
append() así como cualquier otra función que haya agregado, como copyStr() por ejemplo. 
Si no pudo resolver la tarea anterior, tiene la opción de recibir el código para la función append() 
(consulte el cuestionario que precede a esta tarea) para que pueda trabajar en la tarea actual.

Su nueva tarea es escribir una función printStudents() que toma como entrada un puntero que contiene la 
dirección de inicio de una lista vinculada de estudiantes. Luego, su función debería imprimir esta lista de 
estudiantes en la pantalla como se especifica en el siguiente ejemplo. Tu función no debería devolver nada.*/
#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
/* add other prototypes here if needed*/

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;

    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);

    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    tmp = start->next;

    free(start);

    start = tmp;
    tmp = start->next;

    free(start);
    free(tmp);

    return 0;
}

void printStudents(struct student *start)
{
    struct student *ptr = start;
    int i = 0;
    while (ptr != NULL)
    {
        
        
        printf("%s is ", ptr->name);
        printf("%d years old.", ptr->age);
        printf("\n");
        ptr= ptr->next;
    }
    
    
}

struct student *append(struct student * end, struct student * newStudptr)
{
end ->next = newStudptr;
end = newStudptr;
return end;

}



struct student *createStudent(char newName[], int newAge)
{
    struct student *ptr;
    int i = 0;

    ptr = (struct student *) malloc(sizeof(struct student));
    while (newName[i] != '\0')
    {
        ptr->name[i] = newName[i];
        
        i++;
    }
    
    
    ptr->age = newAge;
    ptr->next = NULL;
     

    return ptr;
}

