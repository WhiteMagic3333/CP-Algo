#include <cstdlib>
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

int ans = 0, n;

int sign(ll x) {
    if (x < 0) {
        return -1;
    }
    return 1;
}

void rec(ll cur, int i, int times, vector<ll> &l) {
    if (i == n) {
        ans = max(ans, times);
        return;
    }
    int s1 = sign(cur), s2 = sign(cur - l[i]), s3 = sign(cur + l[i]);
    rec(cur - l[i], i + 1, times + (s1 != s2), l);
    rec(cur + l[i], i + 1, times + (s1 != s3), l);
}
 
void solve()
{
    cin >> n;
    vector<ll> l(n);
    cin >> l;
    for (auto &i : l) {
        i *= 10;
    }
    rec(5, 0, 0, l);
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}