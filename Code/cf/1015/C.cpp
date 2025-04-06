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
    vector<ll> a(n), b(n);
    cin >> a >> b;
    vector<ll> ma(n + 1), mb(n + 1);//opp of a[i] and b[i]
    int same = 0;
    vector<ll> idx(n + 1);//index of a[i];
    for (int i = 0; i < n; i++) {
        idx[a[i]] = i;
        ma[a[i]] = b[i];
        mb[b[i]] = a[i];
        if (a[i] == b[i]) {
            same++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ma[i] != mb[i]) {
            cout << "-1\n";
            return;
        }
    }
    if ((n % 2 == 1 && same != 1) || (n % 2 == 0 && same > 0)) {
        cout << "-1\n";
        return;
    }
    int i = 0, j = n - 1;
    vector<array<int, 2>> ans;
    while (i < j) {
        if (ma[a[i]] != a[j]) {
            int k = idx[ma[a[i]]];
            ans.push_back({k + 1, j + 1});
            swap(idx[a[k]], idx[a[j]]);
            swap(a[k], a[j]);
        }
        while (i < j && ma[a[i]] == a[j]) {
            i++;
            j--;
        }
    }
    cout << ans.size() << "\n";
    for (auto cur : ans) {
        cout << cur[0] << " " << cur[1] << "\n";
    }
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