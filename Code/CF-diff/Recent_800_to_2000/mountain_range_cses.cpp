#include <algorithm>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<stack>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}
 
template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}
 
template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}

int n;

void rec(int i, vector<int> &dp, vector<int> &pre, vector<int> &suf) {
    if (dp[i]) {
        return;
    }
    if (pre[i] != n) {
        rec(pre[i], dp, pre, suf);
        dp[i] = dp[pre[i]] + 1;
    }
    if (suf[i] != n) {
        rec(suf[i], dp, pre, suf);
        dp[i] = max(dp[i], dp[suf[i]] + 1);
    }
}
 
void solve()
{
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    stack<array<int, 2>> mx;
    vector<int> suf(n, n), pre(n, n);
    int mx_idx = 0;
    //prev greater idx
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[mx_idx]) {
            mx_idx = i;
        }
        while (mx.size() && mx.top()[0] <= arr[i]) {
            mx.pop();
        }
        if (mx.size()) {
            pre[i] = mx.top()[1];
        }
        mx.push({arr[i], i});
    }
    //clear
    while(mx.size()) {
        mx.pop();
    }
    //next greater idx
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == arr[mx_idx]) {
            dp[i] = 1;
        }
        while (mx.size() && mx.top()[0] <= arr[i]) {
            mx.pop();
        }
        if (mx.size()) {
            suf[i] = mx.top()[1];
        }
        mx.push({arr[i], i});
    }
    for (int i = 0; i < n; i++) {
        if (!dp[i]) {
            rec(i, dp, pre, suf);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}