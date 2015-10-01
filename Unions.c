#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    const char *name;
    
    union
    {
        int age;
        float weight;
        const char* lastName;    
    };

} Person;

int main(int argc, char **argv)
{

    Person *me = calloc(1, (unsigned) sizeof(Person)); // Declaring a memory space to my instance

    me->name = (const char*)"Jozadaque";
    me->age = 21;
    me->lastName = (const char*)"Batista"; // Doesn't works, 'cause the union has a limit
                                           // and only can store one element between the 
                                           // 3 others. :P
    
    printf("meu nome: %s\n", me->name);
    printf("last Name: %s\n", me->lastName);
    printf("minha idade: %d\n", me->age);

}
