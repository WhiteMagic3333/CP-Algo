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
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for (auto &i : arr) {
        sort(i.begin(), i.end());
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    int mx = -1;
        
    for (int i = 0; i < n; ++i) {
        pq.push({arr[i][0], i, 0});
        mx = max(mx, arr[i][0]);
    }
    
    int ans = 2e9; 
    while (true) {
        array<int, 3> cur = pq.top();
        pq.pop();
        
        ans = min(ans, mx - cur[0]);
        
        if (cur[2] + 1 == 3) {
            break;
        }

        int next_val = arr[cur[1]][cur[2] + 1];
        mx = max(mx, next_val);
        pq.push({next_val, cur[1], cur[2] + 1});
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