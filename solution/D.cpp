#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int d[20][300000];
int n;int w[20];
int m;int up;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    up=pow(2,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=up-1;j++)
        {
            d[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=0;i<n;i++)
    {
        d[1][1<<i]=w[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=up-1;j++)
        {
            if(d[i][j]!=0x3f3f3f3f)
            {
                for(int k=0;k<n;k++)
                {
                    if((j&(1<<k))!=0)
                        continue;
                    if(d[i][j]+w[k]<=m)
                    {
                        d[i][j|(1<<k)]=min(d[i][j|(1<<k)],d[i][j]+w[k]);
                    }
                    else
                    {
                        d[i+1][j|(1<<k)]=min(d[i][j|(1<<k)],w[k]);
                    }
                }
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(d[i][up-1]!=0x3f3f3f3f)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
