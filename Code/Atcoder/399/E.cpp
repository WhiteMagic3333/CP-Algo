#include <unordered_map>
#include <vector>
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
    unordered_map<char, char> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (m.count(s[i]) == 0) {
            m[s[i]] = t[i];
            if (s[i] != t[i]) {
                ans++;
            }
        } else {
            if (m[s[i]] != t[i]) {
                cout << "-1";
                return;
            }
        }
    }
    vector<bool> vis(26, false);
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (!vis[ch - 'a']) {
            char cur = ch;
            bool loop = false;
            for (int i = 0; i < 50; i++) {
                if (m.count(cur)) {
                    cur = m[cur];
                } else {
                    break;
                }
                if (cur == ch) {
                    ans++;
                    loop = true;
                    break;
                }
            }
            vis[cur - 'a'] = true;
            for (int i = 0; i < 50; i++) {
                cur = m[cur];
                vis[cur - 'a'] = true;
                if (cur == ch) {
                    break;
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