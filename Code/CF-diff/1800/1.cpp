#include <numeric>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define all(a) a.begin(),a.end() //imp
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
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string> (n));
    vector<int> present(n);
    for (auto &str : a) {
        cin >> str;
    }
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
            if (b[i][j] == a[j]) {
                present[j] = 1;
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }
    if (accumulate(all(present), 0) != n) {
        cout << "-1";
        return;
    }
    int ans = n + (n - mx) * 2;
    cout << ans;
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