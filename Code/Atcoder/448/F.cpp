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
    int n;
    cin >> n;
    vector<ll> f(2, 0);
    cin >> f;
    vector<ll> cur;
    cur.push_back(1);
    ll ans = 0;
    if (n > 1) {
        vector<vector<ll>> q1, q2, q3, q4;
        for (int i = 0; i < n - 1; i++) {
            ll x, y;
            cin >> x >> y;
            if (x > 0 and y > 0) {
                q1.push_back({abs(x) + abs(y), x, y, i + 2});
            } else if (x < 0 and y > 0) {
                q2.push_back({abs(x) + abs(y), x, y, i + 2});
            } else if (x < 0 and y < 0) {
                q3.push_back({abs(x) + abs(y), x, y, i + 2});
            } else {
                q4.push_back({abs(x) + abs(y), x, y, i + 2});
            }
        }
        sort(q1.begin(), q1.end());
        sort(q2.begin(), q2.end(), greater<> ());
        sort(q3.begin(), q3.end());
        sort(q4.begin(), q4.end(), greater<> ());
        for (auto i : q1) {
            cur.push_back(i[3]);
        }
        for (auto i : q2) {
            cur.push_back(i[3]);
        }
        for (auto i : q3) {
            cur.push_back(i[3]);
        }
        for (auto i : q4) {
            cur.push_back(i[3]);
        }
    }
    cout << cur;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}