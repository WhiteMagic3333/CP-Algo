#include <numeric>
#include <unordered_set>
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
        std::cout << x << ' ';
    return out;
}

unordered_set<long long> sq;

void pre() {
    ll mx = 1e6 + 1;
    for (ll i = 1; i <= mx; i++) {
        sq.insert(i * i);
    }
}

ll ap(ll n) {
    return (n * (n + 1)) / 2LL;
}
 
void solve()
{   //10:42
    int n;
    cin >> n;
    ll sum = ap(n);
    if (sq.find(sum) != sq.end()) {
        cout << "-1";
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    sum = 0;
    vector<int> ans;
    while (q.size()) {
        ll cur = q.front();
        q.pop();
        if (sq.find(sum + cur) != sq.end()) {
            q.push(cur);
            continue;
        }
        ans.push_back(cur);
        sum += cur;
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}