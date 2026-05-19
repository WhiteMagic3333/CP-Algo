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
{   //didnt prove
    //not making the problem clear and solving for something else
    //four times in 2 problems
    //1 hour plus second in a row
    int n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll> (2));
    for (auto &couple : arr) {
        cin >> couple;
    }
    vector<ll> C(2 * n + 1, 0);
    for (auto row : arr) {
        int i = row[0], j = row[1];
        if (i == j) {
            C[i]++;
        }
    }
    vector<ll> pre(2 * n + 1, 0);
    for (int i = 1; i < 2 * n + 1; i++) {
        pre[i] = (C[i] ? 1 : 0) + pre[i - 1];
    }
    string ans = "";
    for (auto row : arr) {
        int i = row[0], j = row[1];
        if (i == j) {
            ans.push_back(C[i] == 1 ? '1' : '0');
        } else {
            ans.push_back((pre[j] - pre[i - 1]) != (j - i + 1) ? '1' : '0');
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