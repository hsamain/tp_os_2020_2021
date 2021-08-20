#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char* argv[])
{
    pid_t pids[4];
    int numbers[4];
    int i;
    
    srand(time(NULL));

    for (i = 0; i < 4; ++i) {
        int fd[2];
        
        pipe(fd);
        pids[i] = fork();
    
        if (pids[i] == 0) {
            int number = rand();
            
            close(fd[0]);
            write(fd[1], (void*)&number, sizeof(int));
            
            printf("pid=%d, nombre=%d\n", getpid(), number);
            exit(0);
        }
        else if (pids[i] > 0) {
            close(fd[1]);
            read(fd[0], (void*)&numbers[i], sizeof(int));
        }
    }

    for (i = 0; i < 4; ++i) {
        wait(NULL);
    }

    printf("les PIDs étaient %d, %d, %d et %d\nles nombres étaient %d, %d, %d et %d\n",
        pids[0], pids[1], pids[2], pids[3], numbers[0], numbers[1], numbers[2], numbers[3]);

    return 0;
}
