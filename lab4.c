#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    char command[255];

    int isOut = 0;


    while (isOut == 0)
    {
    
        fgets(command, 255, stdin);

        if (!strcmp(command, "exit\n"))
        {
            isOut = 1;
        }
        else
        {
            

            switch (pid = fork()){
                case 0:
                    execl("/bin/sh", "/bin/sh", "-c", command, NULL);
                    
                    exit(0);
                    break;
                default:
                    wait();
                    break;
            }
            
        }
        
    }

	return 0;
}
