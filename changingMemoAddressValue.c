#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    int *p = NULL;
    int num = 30;
    
    p = &num; // Here basically I point to memory address of num
    *p = 100; // So, here I assign 100 to the num variable by a implicit way(not to the address)
    
    printf("VALUE OF NUM: %d\n", num); // Value has been changed magically
    

}
