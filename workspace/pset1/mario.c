#include <stdio.h>
#include <cs50.h>
//my idea in solving this is to make a for loop within a for loop, looping from 1 to the number of steps, namely x 
//inside the for loop, another for loop prints the # x+times
int main(void)
{   
    int a,b,c,x; //this decides the number of steps
    //a indicates which step is being processed and b indicates the horizontal length of the steps
    //c indicates the whitespace count, both b and c are functions of a and x
    printf("Height :");
    x = GetInt();
    while(x>23||x<0){
        printf("Retry :");
        x = GetInt();
        
    }
    for( a = 1; a <= x; a = a + 1 ){
        for( c = 1; c <= x-a; c = c + 1 ){
            printf(" ");
        }
        for( b = 1; b <= a+1; b = b + 1 ){
            printf("#");
        }
        printf("\n");
   }
}