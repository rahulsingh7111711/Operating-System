#include <stdio.h>
#include <unistd.h>
int main()
{
    fork();
    printf("LINUX\n");
    fork();
    printf("WINDOWS\n");
    fork();
    printf("IOS\n");
    return 0;
}