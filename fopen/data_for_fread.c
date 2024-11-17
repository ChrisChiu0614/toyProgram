#include "data_for_fread.h"


// create and write the binary data

void write_binary_file(const char *fileName)
{
    FILE *file = fopen(fileName, "wb");
    if (!file)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }

    Student student[] = {
        {101, 85.5}, {102, 90.0}, {103, 78.0}};

    size_t fw_size = fwrite(student, sizeof(Student), 3, file);
    if (fw_size != 3)
    {
        perror("Error writing to file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    printf("create success");
    
}

// create and write the textual data
void write_text_file(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "101 85.5\n");
    fprintf(file, "102 90.0\n");
    fprintf(file, "103 78.0\n");
    fclose(file);
}

void read_text_file_fgets(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    int id;
    float score;

    printf("Reading text file with fgets + sscanf:\n");

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%d %f", &id, &score) == 2)
        {
            printf("ID: %d, Score: %.2f\n", id, score);
        }
    }
}

void read_binary_file(const char *fileName)
{
    FILE *file = fopen(fileName, "rb");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    Student student;
    printf("Reading binary file:\n");
    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        printf("ID: %d, Score: %.2f\n", student.id, student.score);
    }

    if (feof(file))
    {
        printf("End of file reached.\n");
    }
    else if (ferror(file))
    {
        perror("Error reading file");
    }
    fclose(file);
    
}

void read_text_file_fscanf(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int id;
    float score;

    printf("Reading text file with fscanf:\n");
    while (fscanf(file, "%d %f", &id, &score)==2)
    {
       printf("ID: %d, Score: %.2f\n", id, score);
    }
    
    fclose(file);
}