#ifndef DATA_FOR_FREAD_H
#define DATA_FOR_FREAD_H

#include<stdlib.h>
#include<stdio.h>

//student data structure
typedef struct{
    int id;
    float score;
} Student;

void write_binary_file(const char* fileName);
void write_text_file(const char* fileName);
void read_binary_file(const char *fileName);
void read_text_file_fgets(const char *filename);
void read_text_file_fscanf(const char *fileName);
#endif // DATA_FOR_FREAD_H