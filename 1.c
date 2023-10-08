#include <stdio.h>

int main()
{
    int n;
    int i;
    scanf("%d",&n);
    int a[n];
    int b[100];
    for(i=0;i<100;i++) b[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ++b[a[i]];
    }
    for(i=0;i<n;i++)
    {
        if(b[a[i]]!=0)
        {
            printf("%d %d \n",a[i],b[a[i]]);
            b[a[i]]=0;
        }
    }
}
