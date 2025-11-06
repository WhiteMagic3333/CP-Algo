#include <algorithm>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
set<ll> s;

int get_next(int i) {
    auto it = s.upper_bound(i);
    if (it == s.end()) {
        return -1;
    }
    return *it;
}

int get_prev(int i) {
    auto it = s.lower_bound(i);
    if (it == s.begin()) {
        return -1;
    }
    it--;
    return (int)*it;
}

int get_diff(int i) {
    int nxt = get_next(i), prev = get_prev(i);
    if (nxt == -1 && prev == -1) {
        return 0;
    }
    if (nxt == -1) {
        return i - prev;
    }
    if (prev == -1) {
        return nxt - i;
    }
    return min(i - prev, nxt - i);
}
 
void solve()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    cin >> x;
    s.insert(0);
    long long ans = 0;
    for (auto &i : x) {
        if (s.size() == 1) {
            ans += i;
        } else {
            int nxt = get_next(i);
            int prev = get_prev(i);
            if (nxt != -1) {
                int diff = get_diff(nxt);
                if (diff > (nxt - i)) {
                    ans -= diff;
                    ans += nxt - i;
                }
            }
            if (prev != -1) {
                int diff = get_diff(prev);
                if (diff > (i - prev)) {
                    ans -= diff;
                    ans += i - prev;
                }
            }
        }
        s.insert(i);
        ans += get_diff(i);
        cout << ans << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}