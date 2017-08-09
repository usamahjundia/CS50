#include <stdio.h>
#include <cs50.h>
#include <math.h>
//it is 3 am now and i just recoded this because i 'accidentally' coded the whole program in Pascal, sleepy coding is always a bad idea
int main(void)
{   
    //the codes that got commented were used to find out why it fails when the input was 4.2
    //turns out, due to how float works and represented in binary, 4.2 became 4.199999999...
    //so when i converted it to cents and cast it as an int, it became 419, thus adding more coins
    //problem was solved by simply rounding before converting to int
    float change; //the amount of change that is going to be converted
    int changeint,quarter, ten, five, one; //the number of coins that will be outputted
    //change = 4.2;
    printf("O Hai! How much change is owed? \n");
    change = GetFloat();
    while(change <0){
        printf("How much change is owed? \n");
        change = GetFloat();
    }
    //this part is pretty self explanatory
    changeint = (int) round(change*100);
    quarter = (int) (changeint / 25);
    changeint = changeint - quarter*25;
    // printf("%d\n",changeint);
    ten = (int) (changeint/10);
    changeint = changeint -ten*10;
    //printf("%d\n",changeint);
    five = (int) (changeint / 5);
    changeint= changeint - 5*five;
    //printf("%d\n",changeint);
    one = changeint;
    
    //printf("%d , %d , %d , %d\n",quarter, ten, five, one);
    printf("%d\n",quarter+ten+five+one);
}