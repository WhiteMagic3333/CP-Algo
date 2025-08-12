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
    int n, k;
    cin >> n >> k;
    vector<int> s(n), t(n);
    cin >> s >> t;
    map<int, int> rem1, rem2;
    for (auto &i : s) {
        rem1[i % k]++;
    }
    for (auto &i : t) {
        rem2[i % k]++;
    }
    for (auto j : rem1) {
        int i = j.first;
        if ((rem1[i] + rem1[k - i]) != (rem2[i] + rem2[k - i])) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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