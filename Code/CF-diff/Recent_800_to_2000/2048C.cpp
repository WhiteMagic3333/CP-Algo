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

string fix(string &a, string &b) {
    string x = a;
    for (int i = a.length() - 1, j = b.length() - 1; j >= 0; i--, j--) {
        if (a[i] == b[j]) {
            x[i] = '0';
        } else {
            x[i] = '1';
        }
    }
    return x;
}
 
void solve()
{   //30 mins
    //too long today
    string str;
    cin >> str;
    int cnt = count(str.begin(), str.end(), '0');
    int n = str.length();
    cout << "1 " << n << " ";
    if (cnt == 0) {
        cout  << "1 1";
        return;
    }
    int rem_len = -1;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            rem_len = n - i;
            l = i, r = i;
            break;
        }
    }
    string ans = str;
    for (int i = 0; i + rem_len <= n; i++) {
        string s = str.substr(i, rem_len);
        string _xor = fix(str, s);
        if (ans < _xor) {
            l = i, r = i + rem_len - 1;
            ans = _xor;
        }
    }
    cout << l + 1 << " " << r + 1;
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