#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    char buffer[50];

    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Παιδί
        close(pipe_fd[1]); // Κλείνουμε το άκρο εγγραφής
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipe_fd[0]);
    } else if (pid > 0) {
        // Γονέας
        close(pipe_fd[0]); // Κλείνουμε το άκρο ανάγνωσης
        char message[] = "Hello from parent!";
        write(pipe_fd[1], message, strlen(message) + 1);
        close(pipe_fd[1]);
    } else {
        perror("Fork failed");
        return 1;
    }
