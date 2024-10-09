/*En esta tarea continuarás trabajando en la lista vinculada de estudiantes en la que te gustaría almacenar, 
para cada estudiante, su nombre y edad. Como antes, se le proporciona un código que no debe modificar:

Definición de una estructura para el almacenamiento de la información de cada estudiante.
Una función main() para probar su código. 
Prototipos para las funciones createStudent() (de la tarea anterior) y append() (de la tarea actual).
Necesitará la definición de función (de la tarea anterior) para createStudent(), así como cualquier 
otra función que haya agregado, como copyStr() por ejemplo. Si no pudo resolver la tarea anterior, 
tiene la opción de recibir el código para la función createStudent() (consulte el cuestionario que precede
 a esta tarea) para que pueda trabajar en la tarea actual.

Su nueva tarea es escribir una función append() que toma como entrada dos punteros: el primer 
puntero contiene la dirección del final actual de la lista vinculada de estudiantes, 
el segundo puntero apunta a un estudiante recién creado. Su función debe agregar este nuevo estudiante 
a la lista vinculada y devolver la dirección (una estructura estudiante *) del nuevo final de la lista.*/
#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
/* add other prototypes here if needed */

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

    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);

    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);

    return 0;
}
struct student *append(struct student * end, struct student * newStudptr)
{
end ->next = newStudptr;
end = newStudptr;
return end;

}



struct student *createStudent(char newName[50], int newAge)
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