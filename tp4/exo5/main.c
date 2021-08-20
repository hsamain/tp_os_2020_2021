#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int i, j;

    for (i = 0; i < 3; ++i) {
        pid_t pid1 = fork();
        
        if (pid1 == 0) {
            printf("fils %d\n", i + 1);
        
            if (i == 0) {
                for (j = 0; j < 2; ++j) {
                    pid_t pid2 = fork();
                    
                    if (pid2 == 0) {
                        printf("fils %d\n", 4 + j);
                        
                        if (j == 0) {
                            pid_t pid3 = fork();
                            
                            if (pid3 == 0) {
                                printf("fils 7\n");
                                exit(0);
                            }
                        }
                        
                        exit(0);
                    }
                }
                
                exit(0);
            }
            else if (i == 1) {
                pid_t pid2 = fork();
                
                if (pid2 == 0) {
                    pid_t pid3 = fork();
                    
                    if (pid3 == 0) {
                        printf("fils 6\n");
                        exit(0);
                    }
                    
                    exit(0);
                }
            }
            
            exit(0);
        }
    }

    return 0;
}
