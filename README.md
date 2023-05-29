# CUC-ACM-Training-14
## 区间DP与状态压缩DP
### 主讲人 动画与数字艺术学院 20数媒网络 潘东逸杰
### PrimoPan From CUC-Anima Wechat:PrimoJayPan


#### Problem 1
```
#include <bits/stdc++.h>
using namespace std;
int n, a[105], p[105], dp[105][105];
int sum(int l, int r) {
    return p[r] - p[l-1]; //计算区间和
}
void DP() {
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int l = 2; l <= n; l++) //枚举区间长度
    for (int i = 1; i <= n; i++) {//区间左端点
        int j = i+l-1; //区间右端点
        if (j > n) break;//别超了 
        dp[i][j] = INT_MAX;//初始化
        for (int k = i; k < j; k++) //枚举“断电”
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum(i,j)); //状态转移方程模板
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = a[i] + p[i-1]; //前缀和
    }
    DP();
    cout << dp[1][n] << endl;
    return 0;
}
```


#### Problem 2
```
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<ctime>
#include<vector>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 1001
#define MOD 10007
#define E 1e-6
#define LL long long
using namespace std;
char str[N];
int pos[N][N];
int dp[N][N];
bool judge(int i,int j)
{
    if(str[i]=='('&&str[j]==')')
        return true;
    if(str[i]=='['&&str[j]==']')
        return true;
    return false;
}
void print(int i,int j)
{
    if(i>j)
        return;
    if(i==j)
    {
        if(str[i]=='('||str[i]==')')
            printf("()");
        else
            printf("[]");
    }
    else if(pos[i][j]==-1)
    {
        printf("%c",str[i]);
        print(i+1,j-1);
        printf("%c",str[j]);
    }
    else
    {
        print(i,pos[i][j]);
        print(pos[i][j]+1,j);
    }
}
int main()
{
    while(gets(str))
    {
        int n=strlen(str);
        if(n==0)
        {
            printf("\n");
            continue;
        }
 
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
 
        for(int len=1;len<n;len++)
        {
            for(int i=0;i<n-len;i++)
            {
                int j=len+i;
                dp[i][j]=INF;
 
                if(judge(i,j))
                {
                    if(dp[i][j]>dp[i+1][j-1])
                        dp[i][j]=dp[i+1][j-1];
                    pos[i][j]=-1;
                }
 
                for(int k=i;k<j;k++)
                {
                    int temp=dp[i][k]+dp[k+1][j];
                    if(dp[i][j]>temp)
                    {
                        dp[i][j]=temp;
                        pos[i][j]=k;
                    }
                }
            }
        }
        print(0,n-1);
        printf("\n");
    }
 
    return 0;
}
```
