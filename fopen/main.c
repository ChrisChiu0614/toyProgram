#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void write_to_file(FILE* file);
void read_to_file(FILE* file);


int main(){
    char fileName[100];
    char mode[10];

    // Step 1: Ask user for file name and mode
    printf("Enter the file name: ");
    scanf("%s", fileName);
    
    printf("Enter the mode (e.g., r, w, a, w+, a+): ");
    scanf("%s", mode);

    // Step 2: Open the file in the given mode
    FILE* file = fopen(fileName, mode);
    if(file==NULL){
        perror("Error opening file.");
        return EXIT_FAILURE;
    }

    
    while (getchar() != '\n');

    // Step 3: Perform actions based on mode
    if(strcmp(mode,"r")==0||strcmp(mode,"r+")==0){
        printf("\nReading from the file:\n");
        read_to_file(file);
    }else if(strcmp(mode,"w")==0||strcmp(mode,"w+")==0||strcmp(mode,"a")==0){
        printf("\nWriting to the file...\n");
        write_to_file(file);
    }

     // Step 4: Close the file
     fclose(file);
     printf("\nFile operation completed.\n");
     return EXIT_SUCCESS;

}


void write_to_file(FILE* file){
    char buffer[256];
    printf("Enter text to write to the file (end with an empty line):\n");
    while(1){
       fgets(buffer,sizeof(buffer),stdin);
       if(strcmp(buffer,"\n")==0){
        break;
       }
       fputs(buffer, file); 
    }
    
}

void read_to_file(FILE* file){
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), file)!=0){
        printf("%s",buffer);
    }
}