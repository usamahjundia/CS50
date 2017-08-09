#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]){
    if(argc != 2){
        printf("usage = ./caesar integer\n ");
        return 1;
    }else{
        printf("plaintext: ");
        string plaintext = get_string();
        for(int i=0;i<strlen(plaintext);i++){
            //only cipchers alphabet characters, this acts as a filter
            if(plaintext[i] != ' ' && ((plaintext[i] > 64 && plaintext[i] < 91) || (plaintext[i] > 96 && plaintext[i] < 123) )){
                if(plaintext[i] > 96){
                    //basically deciding a number (0-25) to add to 97 or 65 that are the first member of the alphabet, be it capitalized or not
                    //decision is made by getting how far the car is from the 'A' or 'a' and then apllying the caesar to get the number from 0-25 to add to the 'A' or 'a' of the sequence
                    (plaintext[i] = (((plaintext[i]-97) + atoi(argv[1]))%26 ) + 97 );
                }else{
                    (plaintext[i] = (((plaintext[i]-65) + atoi(argv[1]))%26 ) + 65 );
                }
            }
        }
    printf("ciphertext: %s\n",plaintext);
    }
    
    
    return 0;
}