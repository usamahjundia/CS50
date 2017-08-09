/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 const int MAX2 = 65536;


bool search(int value, int values[], int n)
{
    // Since the consttraint of the search algo is to have the complexity bounded of log n,
    // i'm going to utlize the binary search algorithm, in which to use the algo,
    // the array must be 'prepared' by sorting it first
    if(value>=0){
        int left =0, right = n-1;
        while(left<=right){
            printf("Left : %d, Right : %d \n",left,right);
            int middle = (right+left)/2;
            if(values[middle] == value){
                return true;
            }else if(value<values[middle]){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 * the algorithm used is the counting sort algo
 * so that the complexity is somewhat linear (n+k)
 */
void sort(int values[], int n)
{
    int SIZE = MAX2 + 1;
     int elementCount[SIZE];
     int i,j,k;
     for(i=0;i<MAX2+1;i++){
         elementCount[i] = 0;
     }
     int temporaryArray[n];
     for(i=0;i<n;i++){
         elementCount[values[i]] += 1;
     }
     k = 0;
     for(i=0;i<SIZE;i++){
         for(j=0;j<elementCount[i];j++){
             temporaryArray[j+k] = i;
             k++;
         }
     }
     for(i=0;i<n;i++){
         values[i] = temporaryArray[i];
     }
    
}
