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

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n+1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long sum(int idx) {
        long long s = 0;
        for (; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }
};
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> P(n+1, 0);
    for (int i = 0; i < n; i++) {
        int val = 0;
        if (s[i] == 'A') val = 1;
        else if (s[i] == 'B') val = -1;
        else val = 0;

        P[i+1] = P[i] + val;
    }

    vector<ll> comp = P;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    auto get_id = [&](int x) {
        return int(lower_bound(comp.begin(), comp.end(), x) - comp.begin()) + 1;
    };

    Fenwick fw(comp.size());

    long long ans = 0;

    fw.add(get_id(P[0]), 1);

    for (int i = 1; i <= n; i++) {
        int id = get_id(P[i]);

        ans += fw.sum(id - 1);

        fw.add(id, 1);
    }

    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}