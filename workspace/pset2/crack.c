#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <unistd.h>


char ezIterate(int x){
    if(x==0){
        return '\0';
    }else if(x<27){
        return x+64;
    }else{
        return x+70;
    }
}

int main(int argc,string argv[]){
    int i,j,k,l;
    string hash = argv[1];
    printf("%s\n",hash);
    char test[5];
    test[4] = '\0';
    //printf("%s\n",test);
    //help[0] = 'a';
    //printf("SUkses\n");
    //printf("%c",ezIterate(3));
   // test[0] = 'a';
    for(l = 0;l<53;l++){
        for(k = 0;k<53;k++){
            for(j = 0;j<53;j++){
                for(i = 1;i<53;i++){
                    test[0] = ezIterate(i);
                    test[1] = ezIterate(j);
                    test[2] = ezIterate(k);
                    test[3] = ezIterate(l);
                    printf("%s\n",test);
                    if(!strcmp(((char *)crypt(test,"50")),hash)){
                        printf("%s",test);
                        printf("jalan loh\n");
                        return 0;
                    }
                }
            }
        }
    }
    printf("kelar loh\n");
    return 1;
}