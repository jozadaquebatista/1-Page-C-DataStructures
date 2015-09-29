#include <stdio.h>

#define MAX 10
#define true 0
#define false 1

int push(int e);
void pop();
void Draw_menu();
void Show_stack();

int stack[MAX], qtde_el=0, top_el, flag_exit=false;

int main(int argc, char **argv)
{
    
    while(1)
    {
        Draw_menu();
        if(flag_exit == true)
            return 0;
    }    

}



int push(int e)
{

    if(qtde_el == MAX-1)
    {
        printf("Stack full.");
        return 0;
    }
    else
    {
        stack[qtde_el] = e;
        
        top_el = stack[qtde_el];
        
        qtde_el++;
        
        return 1;
    }

}
void pop()
{

    if(qtde_el == 0)
    {
        printf("No data to pop.");
    }
    else
    {        
        top_el = stack[qtde_el-1];
        qtde_el--;
    }

}
void Draw_menu()
{

    int option, new_el;

    printf("\tMenu\n\t====\n\n");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Show Stack");
    puts("4. Exit");
    
    printf("\noption: ");
    scanf("%d", &option);
    
    if(option == 1 || option == 2 || option == 3 || option == 4)
    {
        switch(option)
        {
            case 1:
                puts("*Enter with the element to push to Stack:");
                scanf("%d", &new_el);
                push(new_el);
                break;
                
             case 2:
                pop(new_el);
                break;
                
            case 3:
                Show_stack();
                break;
                
            case 4:
                flag_exit = true;
                break;
                
            default:
                printf("*Incorrect choice, please select the correct option.");
                break;
                
        }
    }

}


void Show_stack()
{

    if(qtde_el == 0)
    {
        printf("*No elements in the stack, nothing to do.");
    }
    else
    {
        int i;
        puts("");
        puts("Current Stack:\n");
        
        for(i = qtde_el; i >= 0; i--)
        {
            printf("\n%d - [ %d ]", i, stack[i]);
        }
        puts("");
    }
    puts("");
}
