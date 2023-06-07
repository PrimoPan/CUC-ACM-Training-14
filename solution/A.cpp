#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e2+5; //实际maxn的两倍（因为要模拟环形）
int n; //石子数量
int sum[maxn]; //重量前缀和
int dp[maxn][maxn]; //区间
 
int dpMin(){
    memset(dp, inf, sizeof(dp));
    for(int i=1; i<=2*n-1; i++) dp[i][i] = 0;
    for(int len=2; len<=n; len++){
        for(int s=1; s<=2*n-len; s++){
            int e = s+len-1;
            for(int k=s; k<e; k++){
                dp[s][e] = min(dp[s][e], dp[s][k]+dp[k+1][e]);
            }
            dp[s][e] += sum[e] - sum[s-1];
        }
    }
    int ans = inf;
    for(int i=1; i<=n; i++){
        ans = min(ans, dp[i][i+n-1]);
    }
    return ans;
}
int dpMax(){
    memset(dp,0,sizeof(dp));
    for(int len=2; len<=n; len++){
        for(int s=1; s<=2*n-len; s++){
            int e = s+len-1;
            for(int k=s; k<e; k++){
                dp[s][e] = max(dp[s][e], dp[s][k]+dp[k+1][e]);
            }
            dp[s][e] += sum[e] - sum[s-1];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i][i+n-1]);
    }
    return ans;
}
 
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){//输入（注意环形）
        cin >> sum[i];
        sum[i+n] = sum[i];
    }
    for(int i=1; i<=2*n-1; i++){ //求前缀和
        sum[i] += sum[i-1];
    }
    cout << dpMin() << endl;
    cout << dpMax() << endl;
}
