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
    string str;
    cin >> str;
    vector<int> f(26, 0);
    for (char ch : str) {
        f[ch - 'a']++;
    }
    int n = str.length();
    for (auto freq : f) {
        if (freq > (n + 1) / 2) {
            cout << "No";
            return;
        }
    }
    cout << "Yes\n";
    priority_queue<pair<int, char>> q;
    for (int i = 0; i < 26; i++) {
        if (f[i]) {
            q.push({f[i], i + 'a'});
        }
    }
    while (q.size()) {
        auto [highest_freq, ch1] = q.top();
        q.pop();
        cout << ch1;
        highest_freq--;
        if (q.size()) {
            auto [s_highest_freq, ch2] = q.top();
            q.pop();
            cout << ch2;
            s_highest_freq--;
            if (s_highest_freq) {
                q.push({s_highest_freq, ch2});
            }
        }
        if (highest_freq) {
            q.push({highest_freq, ch1});
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