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
{   //25 minutes couldnt undestand the problem
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    cin >> a >> b;
    sort(a.begin(), a.end());

    for (int i = 1; i < n; i++) {
        b[i] += b[i - 1];
    }

    int last = n - 1;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int swords = n - i;
        while (b[last] > swords) {
            last--;
        }
        ans = max(ans, a[i] * (last + 1));
    }
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