#include <algorithm>
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
    vector<int> arr(n);
    cin >> arr;
    vector<array<int, 2>> q;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            q.push_back({i, 0});
        } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            q.push_back({i, 1});
        }
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            array<int, 2> _search = {i, 0};
            auto it = lower_bound(q.begin(), q.end(), _search);
            if (it == q.end()) {
                break;
            }
            int idx = it - q.begin();
            if (idx == (q.size() - 1)) {
                break;
            }
            if (q[idx][1] != q[idx + 1][1]) {
                ll r = n - 1;
                if ((idx + 2) < q.size()) {
                    r = q[idx + 2][0];
                }
                if ((r - i + 1) >= 4) {
                    ans += max(0LL, (r - q[idx + 1][0]));
                }
            }
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