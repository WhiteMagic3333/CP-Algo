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
    return out;
}
 
void solve()
{   //26 mins
    int n;
    cin >> n;
    string str;
    cin >> str;
    str += '1';
    int prev = -1;
    for (int i = 0; i <= n; i++) {
        if (str[i] == '1') {
            int z = i - prev - 1;
            if (z == 1) {
                cout << "No";
                return;
            }
            prev = i;
        }
    }
    int cur = 1;
    vector<int> ans(n + 1, 0);
    prev = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == '1') {
            ans[i] = i + 1;
            int cur = i;
            while (prev < i) {
                ans[prev] = cur;
                prev++, cur--;
            }
            prev = i + 1;
        }
    }
    ans.pop_back();
    cout << "Yes\n";
    cout << ans;
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