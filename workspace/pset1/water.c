#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    int duration, bottles; //both variables respectively represents the duration of the shower and how much bottles of water does it worth
    printf("minutes :\n");
    duration = get_int();
    bottles = duration * 12 ;
    printf("%d\n",bottles);
    return 0;
}