#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{

    size_t sz = 0;
    ssize_t len = 0;
    char *curr = NULL;
    char **line = NULL;
    size_t num_lines = 0;
    while ((len = getline(&curr, &sz, stdin)) != -1)
    {
        line = realloc(line, (num_lines + 1) * sizeof(line));
        if (!line)
        {
            perror("realloc failed");
            free(curr);
            return EXIT_FAILURE;
        }
        line[num_lines] = strdup(curr);
        num_lines++;
    }

    for (int i = 0; i < num_lines; i++)
    {
        printf("%s", line[i]);
        free(line[i]);
    }

    free(line);
    free(curr);

    return EXIT_SUCCESS;
}