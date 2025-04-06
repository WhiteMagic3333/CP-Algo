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
    // cout << '\n';
    return out;
}
 
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(m + 1);
    int c = n;
    int i = 0;
    while (c) {
        int last = arr[i].size();
        arr[i].push_back(last);
        i = (i + 1) % (m + 1);
        c--;
    }
    int sz = arr.size();
    if (k <= arr[sz - 2].size()) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
        }
    }
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