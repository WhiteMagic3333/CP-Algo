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
    string s, t;
    cin >> s >> t;
    //if t has 1 early then no
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cout << "-1\n";
            return;
        } else if (s[i] == '1' && t[i] == '1') {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "0\n";
        return;
    }
    vector<int> ans;
    for (int i = idx; i < n; i++) {
        if (s[i] == '0') {
            ans.push_back(i);
        }
    }
    for (int i = n - 1; i > idx; i--) {
        if (t[i] == '0') {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    if (ans.size()) {
        cout << ans;
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
    }
    return 0;
}