/*Le gustaría almacenar los datos de los estudiantes (para cada estudiante, su nombre y edad) en una lista vinculada de 
estudiantes. Se le proporciona la siguiente estructura para almacenar la información de cada estudiante. 
Por favor no modifique esta estructura:

estudiante de estructura {
      nombre de carácter[50];
      edad interna;
      estructura estudiante *siguiente;
};
Su primera tarea es escribir una función createStudent() que tome como entradas una cadena (es decir, el nombre de un estudiante)
y un número entero (su edad) y que devuelva un puntero a una estructura de estudiante que almacena esta información.
 Su función debe asignar dinámicamente la memoria requerida para este estudiante de estructura y luego escribir
  el nombre y la edad del estudiante en esta memoria recién asignada. 

Se le proporciona el prototipo de función createStudent() y una función main() para probar su código; no los modifique:*/


#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);

// Write other function prototypes here (if any)


int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
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
