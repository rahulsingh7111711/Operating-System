#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int file,n;
    char a[100];
    mknod("myfifo",S_IFIFO|0666,0);
    file=open("myfifo",O_RDONLY);
    printf("If you have a write process then type data\n");
    do
    {
        n=read(file,a,sizeof(a));
        a[n]='\0';
        printf("Reader process read %d bytes: %s\n",n,a);
    }while(n>0);
    return 0;
}