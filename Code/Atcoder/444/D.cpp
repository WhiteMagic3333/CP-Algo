#include <algorithm>
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
    vector<ll> arr(n);
    cin >> arr;
    string ans = "";
    int mx = *max_element(arr.begin(), arr.end());
    vector<ll> freq(mx + 5, 0);
    for (auto i : arr) {
        freq[i]++;
    }
    ll rem = n;
    ll extra = 0;
    for (int i = 1; i <= mx + 5; i++) {
        long long d = (rem % 10 + extra % 10) % 10LL;
        extra = (rem + extra) / 10;
        rem -= freq[i];
        ans += to_string(d);
    }
    while(ans.size() && ans.back() == '0') {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}