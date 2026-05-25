#include <unordered_map>
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
    vector<string> arr(n);
    for (auto &row : arr) {
        cin >> row;
    }
    unordered_map<char, int> m;
    int cur = 2;
    for (char ch = 'a'; ch <= 'z'; cur++) {
        if (ch == 'p' || ch == 'w') {
            m[ch] = cur;
            ch++;
        }
        for (int j = 0; j < 3 ; j++) {
            m[ch + j] = cur;
        }
        ch += 3;
    }
    for (auto row : arr) {
        cout << m[row[0]];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}