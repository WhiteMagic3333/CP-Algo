#include <stack>
#include <unordered_set>
#include <vector>
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
{   //fucking irritatin problem
    //1 hour
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    int ans = 1;
    unordered_set<int> s;
    s.insert(arr[0]);
    vector<bool> vis(n + 1, false);
    stack<int> add;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (s.find(arr[i]) == s.end()) {
            add.push(arr[i]);
        } else if (!vis[arr[i]]) {
            cnt++;
            vis[arr[i]] = true;
        }
        if (cnt == s.size()) {
            ans++;
            for (auto it : s) {
                vis[it] = false;
            }
            while (add.size()) {
                s.insert(add.top());
                add.pop();
            }
            cnt = 0;
        }
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