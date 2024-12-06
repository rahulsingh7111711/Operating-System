#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int file,n;
    char s[100];
    mknod("myfifo",S_IFIFO|0666,0);
    printf("Write for Reader process:\n");
    file=open("myfifo",O_WRONLY);
    while(gets(s))
    {
        n=write(file,s,strlen(s));
        printf("Writing %d bytes: %s\n",n,s);
    }
    return 0;
}