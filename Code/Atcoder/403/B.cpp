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
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        int q = 0;
        for (int j = 0; j < t.length(); j++) {
            if ((i + j) >= s.length()) {
                q = 5;
                break;
            }
            if (s[i + j] == '?') {
                q++;
            } else if (s[i + j] != t[j]) {
                q = 5;
                break;
            }
        }
        if (q < 5) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}