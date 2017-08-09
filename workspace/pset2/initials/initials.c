#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    string username = get_string();
    int i;
    if(username[0]!='0' && username[0]!=' '){
        printf("%c",toupper(username[0]));
    }
    for(i=0;i<strlen(username);i++){
        if(isalpha(username[i]) && username[i-1]==' '){
            printf("%c",toupper(username[i]));
        }
    }
    printf("\n");
    
    
    return 0;
}