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

bool contains(string &s, string &cur) {
    for (auto ch : cur) {
        if (count(s.begin(), s.end(), ch) == 0) {
            return false;
        }
    }
    return true;
}
 
void solve()
{
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    int q;
    cin >> q;
    while (q--) {
        string cur;
        cin >> cur;
        bool a = contains(s, cur), b = contains(t, cur);
        if (a && b) {
            cout << "Unknown\n";
        } else if (a) {
            cout << "Takahashi\n";
        } else {
            cout << "Aoki\n";
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