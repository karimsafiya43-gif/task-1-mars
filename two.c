#include <stdio.h>
#include <string.h>
char *transl[]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", "--..",".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", // 0-9
    ".-.-.-", "--..--", "..--..","/"};

char character[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','.',',','?',' '};
int len=sizeof(character)/sizeof(character[0]);


void english(char *x){
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
   fgets(code,1000,stdin);
   code[strcspn(code, "\n")] = 0;
    char *separate = strtok(code," ");
    
    while (separate!= NULL) {
        english(separate);      
        separate = strtok(NULL, " "); 
    }

    printf("\n"); 
    return 0;
}



    