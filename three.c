#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letter(char arr[]){
    int size=strlen(arr);
    //temporary variable to store the value
    char b[100];
    //moves to all the. character of the string till it gets /0 value
    for (int i = 0; arr[i] != '\0'; i++) {
        
//we get this using ascii value of the characters from every ascii value its (position+1) is getting subtracted
    b[i]=(char)((int)(arr[i])-(i+1));
   
}
b[size]='\0';

//Print all the characters of b as a string 
    printf("%s",b);
}

int main(){
    char arr[100];
    printf("enter the message\n");
    scanf("%s",arr);
    //Convert the input to upper case
    for(int i=0;i<strlen(arr);i++){
       arr[i] = (char)toupper((unsigned char)arr[i]);
    }
    letter(arr);
}
