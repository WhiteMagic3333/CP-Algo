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

ll fun(string &str, char ch) {
    int n = str.length();
    //sliding window
    vector<int> idx;
    for (int i = 0; i < n ; i++) {
        if (str[i] == ch) {
            idx.push_back(i);
        }
    }
    int N = idx.size();
    vector<ll> away(N, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        away[i] = idx[i] - i;
        ans += away[i];
    }
    int behind = 0, eq = 0;
    ll mx = ans;
    for (int dis = 0; dis + N <= n; dis++) { //i is cur distance
        while (behind + eq < N && away[behind + eq] == dis) {
            eq++;
        }
        if (dis > 0) {
            int after = N - behind;
            ans = ans + behind - after;
            mx = min(mx, ans);
        }
        behind += eq;
        eq = 0;
    }
    return mx;
}
 
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << min(fun(str, 'a'), fun(str, 'b'));
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