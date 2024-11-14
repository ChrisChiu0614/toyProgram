#include <stdio.h>      // For standard input/output functions
#include <stdlib.h>     // For standard library functions like EXIT_SUCCESS and EXIT_FAILURE
#include <string.h>     // For string manipulation functions like strcmp and snprintf
#include <dirent.h>     // For directory handling functions like opendir, readdir, closedir
#include <sys/types.h>  // For defining data types used in directory operations

int main(int argc, char** argv) {
    // Check if the correct number of command line arguments is provided
    if (argc != 3) {
        printf("Usage: %s <directory_path> <new_prefix>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Retrieve the directory path and new file prefix from command line arguments
    char* dirPath = argv[1];
    char* newPrefix = argv[2];

    // Open the directory specified by dirPath
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        // Print error if directory cannot be opened
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    struct dirent* entry;  // Pointer to hold each directory entry
    int fc = 0;            // File counter for unique numbering

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries ("." and "..")
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Print the current file name
        printf("%s\n", entry->d_name);

        // Construct the old file name with full path
        char oldName[256];
        snprintf(oldName, sizeof(oldName), "%s/%s", dirPath, entry->d_name);

        // Construct the new file name with the specified prefix and a zero-padded counter
        char newName[256];
        snprintf(newName, sizeof(newName), "%s/%s_%02d_%s", dirPath, newPrefix, fc++, entry->d_name);

        // Attempt to rename the file
        if (rename(oldName, newName) == 0) {
            printf("Renamed %s to %s\n", oldName, newName);
        } else {
            // Print error if renaming fails
            perror("Error renaming file");
        }
    }

    // Close the directory after processing all entries
    closedir(dir);
    return EXIT_SUCCESS;
}
