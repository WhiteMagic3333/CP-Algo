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
    /*
1
5

_ _ _ _ _

0 0
4 4
but
atleast 2 out of (0, 0, 4, 4)
1 1
3 3
2
in case of odd only a single element can say 2
    */
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    ll ans = 1;
    vector<ll> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int cur = arr[i];
        if (cur >= (n / 2)) {
            cur = n - 1 - cur;
        }
        freq[cur]++;
    }
    for (int i = 0; i < n / 2; i++) {
        if (freq[i] != 2) {
            ans = 0;
        }
    }
    if ((n % 2 == 0 && freq[n / 2 - 1] != 2) || (n % 2 == 1 && freq[n / 2] != 1)) {
        ans = 0;
    }
    ll m = 998244353;
    for (int i = 0; i < n / 2; i++) {
        ans = (ans * 2) % m;
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