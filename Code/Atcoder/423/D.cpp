#include <ratio>
#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<queue>
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
        std::cout << x << '\n';
    std::cout << '\n';
    return out;
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    queue<vector<ll>> q;
    for (int i = 0; i < n; i++) {
        vector<ll> cur(3, 0);
        cin >> cur;
        q.push(cur);
    }
    vector<ll> ans;
    ll t = 0, people_inside = 0;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq; //(end time, count of people in the group)
    int cnt = 0;
    while (q.size()) {
        while (q.size() && q.front()[2] + people_inside <= k) {
            vector<ll> cur = q.front();
            t = max(t, cur[0]);
            ans.push_back(t);
            pq.push({t + cur[1], cur[2]});
            people_inside += cur[2];
            q.pop();
        }
        while (pq.size() && q.size() && q.front()[2] + people_inside > k) {
            array<ll, 2> cur2 = pq.top();
            pq.pop();
            t = max(t, cur2[0]);
            people_inside -= cur2[1];
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