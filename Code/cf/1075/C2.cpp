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
    ll n;
    cin >> n;
    vector<int> ans(n);
    ans[n - 1] = 1;
    ll rem = (n * (n + 1)) / 2 - ans[n - 1];
    for (int i = n - 2; i > 0; i--) {
        ans[i] = ans[n - 1] ^ (i + 1);
        rem -= ans[i];
    }
    ans[0] = rem;
    if ((ans[0] ^ 1) <= n) {
        cout << ans;
        return;
    }
    vector<bool> pres(n + 1, true);
    pres[ans[0]] = false;
    for (int i = 1; i < n - 1; i++) {
        pres[ans[i]] = false;
        int num = (i + 1) ^ ans[0];
        int num2 = 1 ^ ans[i];
        if (num <= n && pres[num] && num2 <= n) {
            swap(ans[0], ans[i]);
            cout << ans;
            return;
        }
    }
    cout << "-1\n";
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