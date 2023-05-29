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

#### Problem 3
```
#include <algorithm>
#include <iostream>
using namespace std;
long long sta[2005], sit[2005], f[15][2005][105];
int n, k, cnt;

void dfs(int x, int num, int cur) {
  if (cur >= n) {  // 有新的合法状态
    sit[++cnt] = x;
    sta[cnt] = num;
    return;
  }
  dfs(x, num, cur + 1);  // cur位置不放国王
  dfs(x + (1 << cur), num + 1,
      cur + 2);  // cur位置放国王，与它相邻的位置不能再放国王
}

bool compatible(int j, int x) {
  if (sit[j] & sit[x]) return false;
  if ((sit[j] << 1) & sit[x]) return false;
  if (sit[j] & (sit[x] << 1)) return false;
  return true;
}

int main() {
  cin >> n >> k;
  dfs(0, 0, 0);  // 先预处理一行的所有合法状态
  for (int j = 1; j <= cnt; j++) f[1][j][sta[j]] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= cnt; j++)
      for (int x = 1; x <= cnt; x++) {
        if (!compatible(j, x)) continue;  // 排除不合法转移
        for (int l = sta[j]; l <= k; l++) f[i][j][l] += f[i - 1][x][l - sta[j]];
      }
  long long ans = 0;
  for (int i = 1; i <= cnt; i++) ans += f[n][i][k];  // 累加答案
  cout << ans << endl;
  return 0;
}
```
