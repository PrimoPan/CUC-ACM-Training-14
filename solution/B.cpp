#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=510;
const int inf=1000000;
int dp[maxn][maxn],a[maxn];
int main()
{
    int N,i,j,k;
    scanf("%d",&N);
    for(i=1;i<=N;i++) scanf("%d",&a[i]);
    for(i=N;i>=1;i--){
        for(j=i;j<=N;j++){
            if(j-i==0) dp[i][j]=1;
            else if(j-i==1) dp[i][j]=(a[i]==a[j])?1:2;
            else {
                if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=dp[i+1][j-1]+2;
                for(k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }    
        }
    }
    printf("%d\n",dp[1][N]);
    return 0;
}
