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

bool isSmall(string a, string b) {
    for (int i = 0; i < min(a.length(), b.length()); i++) {
        if (a[i] < b[i]) {
            return true;
        }
        if (b[i] < a[i]) {
            return false;
        }
    }
    return false;
}
 
void solve()
{
    string s = "";
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto &str : arr) {
        cin >> str;
    }
    for (auto str : arr) {
        if (s.length() == 0) {
            s += str;
        } else {
            if (isSmall(str + s, s + str)) {
                s = str + s;
            } else {
                s += str;
            }
        }
    }
    cout << s;
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