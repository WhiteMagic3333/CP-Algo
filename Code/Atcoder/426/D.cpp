#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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

int fun(string &str, char ch) { //remove ch
    int cnt = count(str.begin(), str.end(), ch);
    if (cnt == n || cnt == 0) {
        return 0;
    }
    vector<int> pre(n, 0), suf(n, 0);
    for (int i = 0; i < n; i++) {
        pre[i] = 1;
        suf[n - i - 1] = 1;
        if (str[i] == ch) {
            pre[i]++;
        }
        if (str[n - i - 1] == ch) {
            suf[n - i - 1]++;
        }
        if (i != 0) {
            pre[i] += pre[i - 1];
            suf[n - i - 1] += suf[n - i];
        }
    }
    // cout << pre << suf;
    int ans = 1e9, prev = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] != ch) {
            int cur = suf[i];
            if (prev != -1) {
                cur += pre[prev];
            }
            ans = min(ans, cur);
            prev = i;
        }
    }
    ans = min(ans, pre[prev]);
    return ans;
}
 
void solve()
{
    cin >> n;
    string str;
    cin >> str;
    cout << min(fun(str, '0'), fun(str, '1'));
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}