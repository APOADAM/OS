#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Κώδικας για το παιδί
            printf("Child process with PID: %d\n", getpid());
            return 0; // Το παιδί τερματίζει
        } else if (pid > 0) {
            // Κώδικας για τον γονέα
            printf("Parent process with PID: %d created a child with PID: %d\n", getpid(), pid);
        } else {
            perror("Fork failed");
            return 1;
        }
    }
    return 0;
c
