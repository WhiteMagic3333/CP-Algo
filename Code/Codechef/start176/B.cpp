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

int n, c;

ll ap_sum(ll k) {
    return (k * (k + 1)) / 2;
}

void rec(vector<int> &a, int i, ll cost, ll k, ll &ans) {
    if (i == 5) {
        ans = min(ans, cost);
        return;
    }
    rec(a, i + 1, cost + c, k, ans);
    rec(a, i + 1, cost + ap_sum(k + a[i]) - ap_sum(k), k + a[i], ans);
}
 
void solve()
{
    cin >> n >> c;
    string str;
    cin >> str;
    vector<int> a(5);
    for (char ch : str) {
        a[ch - 'A']++;
    }
    ll ans = 1e18;
    rec(a, 0, 0, 0, ans);
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