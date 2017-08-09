/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    //This part of the code handles the cases when the command line arguments is not 2 or three
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // thil part of the code takes the amount of numbers to be generated
    int n = atoi(argv[1]);

    // this handles when 3 arguments are used instead of two, and takes the third argument as the value to seed the random number generator
    //if only the amount of numbers to be generated is inputted, it uses the current time to seed the random number generator
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    //this prints out the numbers to be generated. since drand outputs a nuber between 0 and 1, the maximum number to be generated would be the constant limit. 
    //all other numbers being the truncated value of any number between 0 and limit
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
