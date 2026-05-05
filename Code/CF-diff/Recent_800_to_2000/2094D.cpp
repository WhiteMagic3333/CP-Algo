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
{   //10 mins wiht 1 wrong submission
    string p, s;
    cin >> p >> s;
    if (p[0] != s[0]) {
        cout << "NO";
        return;
    }
    int j = 0;
    for (int i = 0; i < p.length(); ) {
        int c1 = 0, c2 = 0;
        while (i + c1 < p.length() && p[i] == p[i + c1]) {
            c1++;
        }
        while (j + c2 < s.length() && s[j] == s[j + c2]) {
            c2++;
        }
        if (c2 < c1 || c2 > 2 * c1) {
            cout << "NO";
            return;
        }
        i += c1;
        j += c2;
    }
    if (j != s.length()) {
        cout << "NO";
        return;
    }
    cout << "YES";
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