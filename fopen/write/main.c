#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"student.h"
/**
 * practice fprintf and fwrite
 * 
 */
void write_by_fprintf(FILE* file, Student* student){
    for(int i = 0; i < 3; i++){
        fprintf(file,"id=%d, name=%s, score=%2.f\n",student->id,student->name,student->score);
        student++;
    }
}

void write_by_fwrite(FILE* file, Student* student){
   fwrite(student, sizeof(Student), 3, file);
}

int main(){
    Student* student = malloc(3*sizeof(Student));
    student[0].id = 0;
    strcpy(student[0].name, "Alice");
    student[0].score = 77.8;
    student[1].id = 1;
    strcpy(student[1].name,"Bob");
    student[1].score = 55.8;
    student[2].id = 2;
    strcpy(student[2].name,"Chris");
    student[2].score = 99.8;

    
    char fileName[10] = "test.txt";
    FILE* file = fopen(fileName, "wb");
    //write_by_fprintf(file,student);
    write_by_fwrite(file,student);
    fclose(file);
    free(student);
    return EXIT_SUCCESS;

    
}