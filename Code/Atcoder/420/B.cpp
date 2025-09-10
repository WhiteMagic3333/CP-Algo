#include <algorithm>
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
{
    int n, m;
    cin >> n >> m;
    vector<int> pts(n, 0);
    vector<string> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (int i = 0; i < m; i++) {
        int z = 0, o = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '1') {
                o++;
            } else {
                z++;
            }
        }
        char ch = (z < o) ? '0' : '1';
        for (int j = 0; j < n; j++) {
            if ((z == 0 && o == 0) || a[j][i] == ch) {
                pts[j]++;
            }
        }
    }
    int mx = *max_element(pts.begin(), pts.end());
    for (int i = 0; i < n; i++) {
        if (pts[i] == mx) {
            cout << i + 1 << " ";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}