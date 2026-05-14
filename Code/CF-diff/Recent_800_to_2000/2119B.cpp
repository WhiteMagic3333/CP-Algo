#include <algorithm>
#include <numeric>
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
{   //30 mins
    int n;
    cin >> n;
    vector<int> p1(2), p2(2);
    cin >> p1 >> p2;
    ll diff1 = abs(p1[0] - p2[0]);
    ll diff2 = abs(p1[1] - p2[1]);
    ll D = diff1 * diff1 + diff2 * diff2;
    ll totalD = 0;
    vector<ll> a(n);
    cin >> a;
    for (auto i : a) {
        totalD += i;
    }
    if (totalD * totalD < D) {
        cout << "No";
        return;
    }
    ll mx = *max_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    sum -= mx;
    if (mx > sum) {//cirucularly rotating the smaller arm
        ll right = mx - sum;
        right *= right;
        if (right > D) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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