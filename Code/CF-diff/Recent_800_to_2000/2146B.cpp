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
 
void solve()
{   //11:30 okaish,
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);
    vector<int> f(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        s[i] = vector<int> (sz);
        cin >> s[i];
        for (auto j : s[i]) {
            f[j]++;
        }
    }
    for (int i = 1; i < m + 1; i++) {
        if (!f[i]) {
            cout << "No";
            return;
        }
    }
    //find atleast 2 sets whos element frequence in atleast 2
    int cnt = 0;
    for (auto s1 : s) {
        int mn = 1e9;
        for (auto e : s1) {
            mn = min(mn, f[e]);
        }
        if (mn > 1) {
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
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