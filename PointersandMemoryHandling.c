#include <stdio.h>
#include <stdlib.h>

#define MAX 10


typedef struct T
{

    const char *name;
    int age;

    struct T *next;

} friend;

int main( int argc, char **argv)
{
    
    /*
    *
    * Here we can observe the behaviour of calloc(that initialize all fields
    * with a zero).
    * avantages of using calloc: more safe.
    *
    * You could try to do with malloc, but that doesn't will works correctly.
    * 
     */
    
    friend *f= calloc(4, sizeof(friend));  // Here I allocated 4 instances of friend struct in memory.
    
    (f)->name = "Jozadaque";
    (f)->age = 21;
    //f++;

    (f+1)->name = "Flavio"; 
    (f+1)->age = 28;


    (f+2)->name = "Silvio";
    (f+2)->age = 19;

    (f+3)->name = "Estevao";
    (f+3)->age = 33;

    (f+4)->name = "Lucas";
    (f+4)->age = 52;
    
    
    // Making a linked list without any problem
    (f)->next = (friend*)(f+1);
    (f+1)->next = (friend*)(f+2);
    (f+2)->next = (friend*)(f+3);
    (f+3)->next = (friend*)(f+4);
    
    int count=0;
    while(f->next != NULL)
    {
        printf("%d\n", count);
        count++;
        f->next = (f+count)->next;
        
        if(f->next == NULL)
            break;
    }
    
    
    // This part remake link between lists
    int loop=0;
    for(; loop < 5; loop++)
    {
        (f+loop)->next = (f+(loop+1));
        // (f+loop)->next = (f+(loop+1))->next; <-That form works too, but I don't now how?(?-?)
    }
    // ------------------------------------
    
    printf("\n\n%s\n", ((f)->next->name));
    printf("%d\n\n", ((f)->next->age));
    
    {
        int i;
        for(i = 4; i >= 0; i--)
        {
            puts((f+i)->name);
            printf("%d\n", (f+i)->age);        
        }
    }
    
    puts("\n\nADDRESS OF POINTER(F+3)\n=======================\n");
    printf("%a\n", (f+3));
    printf("%p\n", (f+3));
    printf("%p\n\n", (void*)(f+3));
    puts("-----------------------");
    
    free(f);
    
    /*
    * We free the first pointer, What happens if we try to print out the pointer in 3 position? 
     */
    
    puts((f+3)->name); // !!YEAH!! It is still there, so, to free completly
                       // the memory space alocatted, we have to do a loop with free().
                       
    printf("%p\n", (f+3)->name); // WTF? why the pointer changed the memory address?
                                 // and why that still maintain its address. 
                                 
    const char *str = (char*)0x400880; // Memo addres of pointer f+3(but it can change), that I can't access from another process(Like another C program)
    
    printf("\n%a\n\n", str);
    printf("\n%s\n\n", str);
    
    const char *lol = str;
    
    printf( "%s\n",(char*)lol);

    /*while(1)
    {
        int j;
        for(j=0; j<100000*2; j++);
        printf( "%s\n", str++);        
    }*/
}
