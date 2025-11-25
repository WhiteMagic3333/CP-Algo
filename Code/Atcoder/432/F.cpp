#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
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
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    if (sum % n != 0) {
        cout << "-1";
        return;
    }
    priority_queue<pair<ll, int>> less, more;
    ll avg = sum / n;
    for (int i = 0; i < n; i++) {
        if (arr[i] < avg) {
            less.push({avg - arr[i], i});
        } else if (arr[i] > avg) {
            more.push({arr[i] - avg, i});
        }
    }
    vector<array<ll, 3>> ans;
    while (less.size()) {
        pair<ll, int> l = less.top(), m = more.top();
        less.pop();
        more.pop();
        ans.push_back({m.second + 1, l.second + 1, min(m.first, l.first)});
        if (l.first < m.first) {
            m.first -= l.first;
            more.push(m);
        } else if (m.first < l.first) {
            l.first -= m.first;
            less.push(l);
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}