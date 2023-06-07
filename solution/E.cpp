#include <stdio.h>
#include <string.h>
int f[1<<20],a[105]={0};
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
    int num=(1<<m);    // m种口味的各种组合总的状态数
	int i,j;
	for (i=0;i<num;i++)
    {
		f[i]=105;
	}
	for (i = 0;i<n;i++)
	{
		for (j = 0;j<k;j++)
		{
			int t;
			scanf("%d",&t);
			a[i] = a[i]|(1<<(t-1));
		}
	}
	f[0]=0;
	for (i=0;i<n;i++)
	   for (j=0;j<1<<m;j++)
	   {
		   if (f[j]>100) continue;
		   f[j|a[i]]= (f[j|a[i]]<f[j]+1)? f[j|a[i]] : f[j]+1;
	   }
	if (f[num - 1]==105) printf("-1");
	else printf("%d",f[num - 1]);
	return 0;
}
