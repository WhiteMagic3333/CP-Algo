#include <algorithm>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;

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
std::istream& operator>>(std::istream& in, std::vector<T>& v) {
    for (T& x : v)
        in >> x;
    return in;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v) {
    for (const T& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
    return out;
}

ll sz = 1e6 + 5;

vector<long long> fact(sz + 1), inv_fact(sz + 1);

ll mod = 998244353;

// Compute factorials and their inverses modulo p
long long modExp(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

void computeInverseFactorials(int n, long long p, vector<long long>& fact, vector<long long>& inv_fact) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % p;
    }

    inv_fact[n] = modExp(fact[n], p - 2, p);

    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % p;
    }
}

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<ll> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    computeInverseFactorials(n, mod, fact, inv_fact);
    ll ans = 1;

    int l = 0, r = 0;
    ll cur = 1;
    while (r < n) {
        int f = 1;
        while (r + 1 < n && arr[r + 1] == arr[r]) {
            r++;
            f++;
        }
        cur = (cur * inv_fact[f]) % mod;  // ✅ FIXED

        while (l < r && (arr[r] - arr[l]) > d) {
            f = 1;
            while (l < r && arr[l + 1] == arr[l]) {
                l++;
                f++;
            }
            cur = (cur * fact[f]) % mod;  // ✅ FIXED
            l++;
        }

        ans = (ans * cur) % mod;
        ans = (ans * fact[r - l + 1]) % mod;
        r++;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
