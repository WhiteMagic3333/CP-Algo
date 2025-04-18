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
 
void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> t(n);
    cin >> t;
    sort(t.begin(), t.end());
    int ans = n - k;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    for (int i = 0; i < ans; i++) {
        q.push({t[i] + 1, i});
    }
    while (q.size() > 0 && q.top()[0] <= d) {
        ans++;
        int idx = q.top()[1];
        int time = q.top()[0] + t[idx];
        q.pop();
        q.push({time, idx});
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