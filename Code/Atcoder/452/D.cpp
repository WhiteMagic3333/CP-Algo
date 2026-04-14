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
    string s, t;
    cin >> s >> t;
    ll n = s.length();
    ll ans = (n * (n + 1)) / 2;
    vector<vector<ll>> idx(26);
    for (int i = 0; i < n; i++) {
        idx[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        idx[i].push_back(n + 1);
    }
    ll tn = t.size();
    for (int i = 0; i < n; i++) {
        int cur = i;
        int j = 0;
        while (j < tn) {
            char ch = t[j];
            int match_idx = *lower_bound(idx[ch - 'a'].begin(), idx[ch - 'a'].end(), cur);
            if (match_idx == n + 1) {
                cur = n + 1;
                break; 
            }
            cur = match_idx + 1; 
            j++;
        }
        ans -= max(0LL, (n - cur + 1));
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