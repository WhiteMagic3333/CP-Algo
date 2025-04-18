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
    vector<vector<ll>> arr(n, vector<ll> (n)), p_sum(n, vector<ll> (n, 0));
    for (auto &row : arr) {
        cin >> row;
    }
    for (auto &row : arr) {
        sort(row.begin(), row.end());
    }
    vector<ll> nums;
    for (int j = 0; j < arr.size(); j++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            nums.push_back(arr[j][i]);
            sum += arr[j][i];
            p_sum[j][i] = sum;
        }
    }
    ll ans = 0;
    for (auto i : nums) {
        ll s1 = score(arr[0], i);//score from row[0];
        ll cur = 0;
        for (int i = 1; i < n; i++) {
            ans += (s1)
        }
    }
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