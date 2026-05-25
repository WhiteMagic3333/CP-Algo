#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    //invariant is the sum of the element
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    ll low = 0, high = 3e14;
    ull mx = (1LL << 63);
    ull ans = mx;
    vector<ll> temp = arr;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll to_add = mid;
        temp[0] = arr[0] - to_add;
        ull op = to_add;
        bool valid = true, overflow = false;
        for (int i = 2; i < n; i++) {
            if (temp[i] <= temp[i - 1]) {
                to_add -= (temp[i - 1] + 1 - temp[i]);
            }
            if (to_add < 0) {
                valid = false;
                break;
            }
            op += to_add;
            if (op > mx) {
                overflow = true;
                break;
            }
        }
        if (overflow) {
            high = mid - 1;
        } else {
            if (valid) {
                ans = min(ans, op);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
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