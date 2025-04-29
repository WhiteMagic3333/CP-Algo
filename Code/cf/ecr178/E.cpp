#include <algorithm>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int q;
    cin >> q;
    vector<string> queries(q);
    for (auto &s : queries) {
        cin >> s;
    }
    //precalculate
    vector<ll> dp(n, 1e9);
    vector<vector<int>> idx(k);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            if (idx[j].size()) {
                dp[i] = min(dp[i], dp[idx[j].back()] + 1);
            } else {
                dp[i] = 1;
            }
        }
        idx[str[i] - 'a'].push_back(i);
    }
    for (auto &row : idx) {
        reverse(row.begin(), row.end());
    }
    //shoot
    for (auto &s : queries) {
        int i = -1;
        bool found = true;
        for (char &ch : s) {
            int j = ch - 'a';
            auto it = upper_bound(idx[j].begin(), idx[j].end(), i);
            if (it == idx[j].end()) {
                found = false;
                break;
            } else {
                i = *it;
            }
        }
        if (!found) {
            cout << "0\n";
        } else {
            cout << dp[i] << "\n";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}