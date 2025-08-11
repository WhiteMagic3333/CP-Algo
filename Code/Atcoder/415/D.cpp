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

ll get_stickers(ll &empty, ll &a, ll &b) {
    ll loss_per_transaction = a - b;
    ll extra = empty - a + 1;
    ll transactions = extra / loss_per_transaction + (extra % loss_per_transaction > 0);
    empty = empty - loss_per_transaction * transactions;
    return transactions;
}
 
void solve()
{
    long long n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<ll>> arr(m, vector<ll> (3));
    for (auto &i : arr) {
        cin >> i[1] >> i[2];
        i[0] = i[1] - i[2];
    }
    sort(arr.begin(), arr.end());
    ll empty = n;
    ll ans = 0;
    for (auto &i : arr) {
        if (i[1] <= empty) {
            ans += get_stickers(empty, i[1], i[2]);
        }
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