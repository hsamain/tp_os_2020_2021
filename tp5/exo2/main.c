#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    pid_t pid = fork();

    if (pid == 0) {
        for (;;) {
          sleep(3);
        }
    }
    
    else {
        int running = 1;
        while (running) {
            printf("What do you want to do?\n"
                   "- 's': sleep\n"
                   "- 'r': restart\n"
                   "- 'q': quit\n");
                   
            switch (getchar()) {
                case 's':
                    kill(pid, SIGSTOP);
                    break;
                    
                case 'r':
                    kill(pid, SIGCONT);
                    break;
                    
                case 'q':
                    kill(pid, SIGKILL);
                    running = 0;
                    break;
            }
        }
		
        wait(NULL);
    }
}

