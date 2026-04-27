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
{   //1100, 34+7 minutes
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    vector<int> cost(n);
    cin >> cost;
    //first remote the smallest energy card from k till pth is first
    ll ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    int i = 0;
    while (m > 0) {
        if (i == p) {
            if (cost[i] <= m) {
                ans++;
                m -= cost[i];
                cost.push_back(cost[i]);
                p = cost.size() - 1;
                i++;
                continue;
            } else {
                break;
            }
        }
        pq.push(cost[i]);
        if (pq.size() == k) {
            int c = pq.top();
            if (c <= m) {
                m -= c;
                cost.push_back(c);
                pq.pop();
            } else {
                break;
            }
        }
        i++;
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