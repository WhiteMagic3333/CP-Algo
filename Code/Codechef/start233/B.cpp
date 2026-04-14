#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 998244353
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

const int MAXN = 200005;

ll f[MAXN], invF[MAXN];

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void pre() {
    f[0] = invF[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    invF[MAXN - 1] = binpow(f[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i >= 1; i--) {
        invF[i] = invF[i + 1] * (i + 1) % mod;
    }
}

vector<int> z_algo(const vector<int>& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 5, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll perms = f[n];
    for (auto i : cnt) {
        if (i) {
            perms = perms * invF[i] % mod;
        }
    }

    auto z_a = z_algo(a);
    int period = n;
    for (int i = 1; i < n; i++) {
        if (z_a[i] + i == n && n % i == 0) {
            period = i;
            break;
        }
    }

    vector<int> rev = a;
    reverse(rev.begin(), rev.end());

    vector<int> str = rev;
    str.push_back(-1);
    str.insert(str.end(), a.begin(), a.end());
    
    for (int i = 0; i < n - 1; i++) {
        str.push_back(a[i]);
    }

    auto z_comb = z_algo(str);
    bool has_shift = false;
    for (int i = n + 1; i < str.size(); i++) {
        if (z_comb[i] == n) {
            has_shift = true;
            break;
        }
    }

    ll cn_1 = has_shift ? period : (2LL * period);
    ll cn = (a == rev) ? 1 : 2;

    ll ans = (1LL * (n - 2) * perms) % mod;
    ans = (ans + cn_1) % mod;
    ans = (ans + cn) % mod;
    ans = (ans + 1) % mod;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    pre();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}