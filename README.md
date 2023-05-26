# CUC-ACM-Training-14
## 区间DP与状态压缩DP
### 主讲人 动画与数字艺术学院 20数媒网络 潘东逸杰
### PrimoPan From CUC-Anima Wechat:PrimoJayPan

```
#include <bits/stdc++.h>
using namespace std;
int n, a[105], p[105], dp[105][105];
int sum(int l, int r) {
    return p[r] - p[l-1];
}
void go() {
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int l = 2; l <= n; l++)
    for (int i = 1; i <= n; i++) {
        int j = i+l-1;
        if (j > n) break;
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum(i,j));
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = a[i] + p[i-1];
    }
    go();
    cout << dp[1][n] << endl;
    return 0;
}
```
