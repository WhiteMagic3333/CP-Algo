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
    int i = 0, n = str.length();
    char cur, prev = str[0];
    int prev_count = 1, cur_count = 0;
    long long ans = 0;
    while (i + 1 < n && str[i] == str[i + 1]) {
        i++;
        prev_count++;
    }
    i++;
    while (i < n) {
        cur = str[i];
        cur_count = 1;
        while (i + 1 < n && str[i] == str[i + 1]) {
            cur_count++;
            i++;
        }
        if (cur == (prev + 1)) {
            ans += min(cur_count, prev_count);
        }
        prev = cur;
        prev_count = cur_count;
        i++;
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