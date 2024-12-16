#include <iostream>
using namespace std;

const int MAX = 1e5 + 5;

int n;
int a[MAX];
int cnt[MAX];
int dp[MAX];

int main() {
    cin >> n;
    for (int i = 1; i <= MAX; i++) {
        dp[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= MAX-1; i++) {
        if(dp[i]==-1)
        dp[i] = max(cnt[i] * i + dp[i-1] + dp[i+1],0);
        if (dp[i-1]!=-1) dp[i-1] = -1;
        if (dp[i+1]!=-1) dp[i+1] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= MAX-1; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
