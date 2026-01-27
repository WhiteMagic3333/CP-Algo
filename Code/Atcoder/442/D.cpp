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

vector<ll> seg;
 
ll tree_size;
 
void pre(int n) {
    tree_size = n;
    seg.resize(2 * n, 0);
}
 
void build(int idx, int element) {
    idx += tree_size;
    seg[idx] = element;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }
}
 
long long query(int l, int r) {
    ll sum = 0;
    l += tree_size;
    r += tree_size;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += seg[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += seg[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    cin >> arr;
    pre(n);
    for (int i = 0; i < n; i++) {
        build(i, arr[i]);
    }
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int i;
            cin >> i;
            int a = query(i - 1, i - 1);
            int b = query(i, i);
            build(i - 1, b);
            build(i, a);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(l, r) << "\n";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}