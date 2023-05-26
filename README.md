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
