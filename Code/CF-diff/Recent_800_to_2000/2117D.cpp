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
{   //upsolved
    //could have done better brain fog
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    ll b = 2 * arr[0] - arr[1];
    if (b < 0 || (b % (n + 1)) != 0) {
        cout << "No";
        return;
    }
    b /= (n + 1);
    ll a = arr[0] - n * b;
    if (a < 0) {
        cout << "No";
        return;
    }
    for (int i = 1; i <= n; i++) {
        ll cur = arr[i - 1] - (a * i + b * (n - i + 1));
        if (cur != 0) {
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