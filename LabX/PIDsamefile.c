#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    FILE *file = fopen("pids.txt", "w");

    if (file == NULL) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Παιδί
        fprintf(file, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        // Γονέας
        fprintf(file, "Parent PID: %d\n", getpid());
    } else {
        perror("Fork failed");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
