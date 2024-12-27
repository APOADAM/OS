#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum) {
    printf("Child received signal %d from parent.\n", signum);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Παιδί
        signal(SIGUSR1, signal_handler);
        pause(); // Περιμένει για σήμα
    } else if (pid > 0) {
        // Γονέας
        sleep(1); // Περιμένει το παιδί να ρυθμίσει τον handler
        kill(pid, SIGUSR1);
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
