#include<stdlib.h>
#include<stdio.h>

int main(){
    char fileName[100];
    printf("Enter file name: \n");
    scanf("%s",fileName);

    while(getchar()!='\n');

    FILE* file = fopen(fileName,"r");
    if(file == NULL){return EXIT_FAILURE;}

    int c ;
    while((c = fgetc(file))!=EOF){
        printf("%c",c);
    }

    fclose(file);
    return EXIT_SUCCESS;
    
}