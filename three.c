#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letter(char arr[]){
    int size=strlen(arr);
     char b[100];
    
    for (int i = 0; arr[i] != '\0'; i++) {
        

    b[i]=(char)((int)(arr[i])-(i+1));
   
}
b[size]='\0';


    printf("%s",b);
}

int main(){
    char arr[100];
    printf("enter the message\n");
    scanf("%s",arr);
    for(int i=0;i<strlen(arr);i++){
       arr[i] = (char)toupper((unsigned char)arr[i]);
    }
    letter(arr);
}