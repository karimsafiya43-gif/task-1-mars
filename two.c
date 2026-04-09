#include <stdio.h>
#include <string.h>
//create an array to insert all the morse code for each character
char *transl[]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", "--..",".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", // 0-9
    ".-.-.-", "--..--", "..--..","/"};
//corresponding to each code define the character
char character[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','.',',','?',' '};
int len=sizeof(character)/sizeof(character[0]);

//create a function to convert morse code to english
void english(char *x){
    //check if the morse code corresppnds to the letter by comparison of the string
    for(int i=0;i<len;i++){
    if(strcmp(transl[i],x)==0){
        printf("%c",character[i]);
        return;}
}
printf("invalid\n");
}

int main(){
   
    char code[1000];
    printf("enter the morse message\n");

    //take the input of the string fgets is used so that spaces are also read
   fgets(code,1000,stdin);

    //use strcpn to find \n and replace it with 0 
   code[strcspn(code, "\n")] = 0;

    //strtok is used to break the string into tokens
    char *separate = strtok(code," ");

    //till the time we get the morse code in the string it will keep on translating it into english
    while (separate!= NULL) {
        english(separate);      
        separate = strtok(NULL, " "); 
    }

    printf("\n"); 
    return 0;
}



    
