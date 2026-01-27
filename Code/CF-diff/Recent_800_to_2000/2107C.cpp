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
{
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<ll> arr(n);
    cin >> arr;
    ll mx_sum = -1e18, cur_sum = -1e18;
    ll idx = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            arr[i] = -1e18;
            idx = i;
        }
        cur_sum = max(arr[i], cur_sum + arr[i]);
        mx_sum = max(mx_sum, cur_sum);
    }
    if (mx_sum > k) {
        cout << "No";
        return;
    } else if (mx_sum == k) {
        cout << "Yes\n";
        cout << arr;
        return;
    } else if (idx == -1) {
        cout << "No";
        return;
    }

    ll sum = -1e18;
    ll mx_left_sum = -1e18, mx_right_sum = -1e18;
    cur_sum = -1e18;
    for (int i = 0; i < idx; i++) {
        mx_left_sum = max(arr[i], mx_left_sum + arr[i]);
    }
    cur_sum = -1e18;
    for (int i = n - 1; i > idx; i--) {
        mx_right_sum = max(arr[i], mx_right_sum + arr[i]);
    }
    sum = max({mx_left_sum, mx_right_sum, mx_left_sum + mx_right_sum, 0LL});
    arr[idx] = k - sum;
    cout << "Yes\n";
    cout << arr;
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