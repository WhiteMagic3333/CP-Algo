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

vector<ll> F(2, 1);

ll mx = 2e5;


void pre() {
    for (int i = 2; i <= 2e5; i++) {
        ll cur = F[i - 1] + F[i - 2];
        F.push_back(cur);
        if (F.back() > mx) {
            break;
        }
    }
}

//took 30 + min but worth it
void solve()
{   //let F[n] is actual fibonacci with f[0] = 1, f[1] = 1
    //so f[n] = F[n - 1] * f[2] + f[n - 2] * f[1]
    ll n, k;
    cin >> n >> k;

    if (k > F.size()) {
        cout << "0";
        return;
    }
    //n = F[k - 1] * a + F[k - 2] * b;
    //b = (n - F[k - 1] * a) / (F[k - 2]);
    ll ans = 0;
    for (ll a = 0; a <= 2e5; a++) {
        ll num = (n - F[k - 1] * a);
        if (num >= 0 && num % F[k - 2] == 0 && (num % F[k - 2]) <= a) {
            ans++;
        }
        if (num < 0) {
            break;
        }
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}