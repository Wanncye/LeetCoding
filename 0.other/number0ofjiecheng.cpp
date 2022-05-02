#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,c=0;
    scanf("%d",&n);
    for(i=5;i<=n;i++){
        j=i;
        while(j!=0){
            if(j%5==0)
                c++;
            else
                break;
            j/=5;
        }
    }
    printf("%d",c);
}