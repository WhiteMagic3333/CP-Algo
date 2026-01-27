#include <array>
#include <queue>
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

ll n;

ll calc(ll c, priority_queue<array<ll, 4>> pq, ll add) {
    priority_queue<array<ll, 4>> unused;
    ll ans = 0;
    while (pq.size()) {
        array<ll, 4> cur = pq.top();
        ll w = cur[1], v = cur[2], k = cur[3];
        pq.pop();
        ll items_count = 0;
        if (k * w <= c) {
            items_count = k;
        } else {
            items_count = c / w;
            unused.push({cur[0], w, v, k - items_count});
        }
        ans += v * items_count;
        c -= items_count * w;
    }
    c += add;
    ll f_ans = ans;
    while (unused.size()) {
        array<ll, 4> cur = unused.top();
        ll w = cur[1], v = cur[2], k = cur[3];
        unused.pop();
        ll items_count = 0;
        if (k * w <= c) {
            items_count = k;
        } else {
            items_count = c / w;
        }
        f_ans = max(f_ans, v * items_count + ans);
    }
    return f_ans;
}
 
void solve()
{
    ll c;
    cin >> n >> c;
    priority_queue<array<ll, 4>> pq, unused;
    for (int i = 0; i < n; i++) {
        ll w, v, k;
        cin >> w >> v >> k;
        ll net_val = 2 * v;
        if (w == 1) {
            net_val = 6 * v;
        } else if (w == 2) {
            net_val = 3 * v;
        }
        pq.push({net_val, w, v, k});
    }
    calc(c - 3, pq, 3);
    cout << max({calc(c, pq, 0), calc(c - 1, pq, 1), calc(c - 2, pq, 2), calc(c - 3, pq, 3)});
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}