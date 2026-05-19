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

vector<ll> diff(vector<ll> &f1, vector<ll> &f2) {
    vector<ll> f(26, 0);
    for (int i = 0; i < 26; i++) {
        f[i] = f1[i] - f2[i];
    }
    return f;
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<ll>> af(n + 1, vector<ll> (26, 0));
    vector<vector<ll>> bf(n + 1, vector<ll> (26, 0));
    for (int i = 0; i < n; i++) {
        af[i + 1] = af[i];
        bf[i + 1] = bf[i];
        af[i + 1][a[i] - 'a']++;
        bf[i + 1][b[i] - 'a']++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        vector<ll> f1 = diff(af[r + 1], af[l]);
        vector<ll> f2 = diff(bf[r + 1], bf[l]);
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += max(0LL, f2[i] - f1[i]);
        }
        cout << ans << "\n";
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
    }
    return 0;
}