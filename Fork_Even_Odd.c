#include <stdio.h>
#include <unistd.h>
int main()
{
    int s;
    printf("Enter array size: ");
    scanf("%d",&s);
    int a[s];
    printf("Enter array elements: ");
    for(int x=0;x<s;x++)
    {
        scanf("%d",&a[x]);
    }
    int n=fork();
    int odd_s=0, even_s=0, i;
    if(n>0)
    {
        for(int i=0;i<s;i++)
        {
            if(a[i]%2==0)
            {
                even_s+=a[i];
            }
        }
        printf("Parent Process\n");
        printf("Sum of even numbers: %d\n",even_s);
    }
    else
    {
        for(int i=0;i<s;i++)
        {
            if(a[i]%2!=0)
            {
                odd_s+=a[i];
            }
        }
        printf("Child Process\n");
        printf("Sum of odd numbers: %d\n",odd_s);
    }
    return 0;
}
