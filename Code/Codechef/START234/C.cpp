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
    vector<ll> a(n);
    cin >> a;

    vector<vector<int>> b(n, vector<int>(n, 0));
    
    for (int l = n - 1; l >= 0; l--) {
        vector<int> f(n + 1, 0); 
        int u = 0;
        
        for (int r = l; r < n; r++) {
            if (++f[a[r]] == 1) {
                u++;
            }
            else if (f[a[r]] == 2) {
                u--;
            }

            b[l][r] = (u > 0) && (l == r || (b[l + 1][r] && b[l][r - 1]));
        }
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = b[0][i - 1] ? 0 : dp[i - 1] + 1;
        
        for (int j = 1; j < i; j++) {
            if (b[j][i - 1]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[n];
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