#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    // Step 1: Create a new process
    pid_t pid = fork();

    if (pid < 0)
    { // Step 2: Error handling for fork
        perror("fork failed");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    { // Step 3: Child process
        printf("Child process: Executing 'ls' command...\n");
        char *args[] = {"/bin/ls", "-l", NULL};
        char *evnp[] = {NULL};

        if (execve(args[0], args, evnp) == -1)
        {
            perror("execve failed"); // Error if execve fails
            return EXIT_FAILURE;
        }
    }
    else
    { // Step 6: Parent process
        int status;
        printf("Parent process: Waiting for child to complete...\n");

        // Wait for child process to complete and get its exit status
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Parent process: Child exited with status %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Parent process: Child did not exit normally\n");
        }
    }
}