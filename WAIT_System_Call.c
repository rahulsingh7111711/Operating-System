#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        printf("I am Child\n");
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("I am Parent\n");
        printf("The Child PID = %d\n",pid);
    }
    return 0;
}