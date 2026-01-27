#include <unordered_set>
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

ll nC3(ll cur) {
    if (cur < 3) {
        return 0;
    }
    return (cur * (cur - 1) * (cur - 2)) / 6;
}
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<unordered_set<int>> cur(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cur[a].insert(b);
        cur[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        ll rem = n - (int)cur[i].size() - 1;
        cout << nC3(rem) << " ";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}