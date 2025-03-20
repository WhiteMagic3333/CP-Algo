#include <vector>
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
        std::cout << x;
    std::cout << '\n';
    return out;
}
 
void solve()
{
    vector<int> ans;
    int n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    
    vector<bool> pre_valid(n, true);
    vector<bool> suf_valid(n, true);
    vector<ll> diff(n + 2, 1e10);  // This stores differences and large values at edges
    ll prev_def = 0, cur_def = 0, next_def = 1e10;
    diff[0] = 0;
    
    // Compute the prefix validity array (increasing sequence)
    for (int i = 1; i < n; ++i) {
        diff[i] = cur_def = arr[i] - arr[i - 1];
        pre_valid[i] = pre_valid[i - 1] && (cur_def > prev_def) && (arr[i] > arr[i - 1]);
        prev_def = cur_def;
    }
    
    // Compute the suffix validity array (decreasing sequence)
    for (int i = n - 1; i > 0; --i) {
        cur_def = arr[i] - arr[i - 1];
        suf_valid[i - 1] = suf_valid[i] && (cur_def < next_def) && (arr[i] > arr[i - 1]);
        next_def = cur_def;
    }

    // Check validity for the first element (special case)
    ans.push_back(suf_valid[1]);
    
    // Check validity for all other elements (except the first and last)
    for (int i = 1; i < n - 1; ++i) {
        bool valid = true;
        valid = valid && pre_valid[i - 1] && suf_valid[i + 1];
        cur_def = arr[i + 1] - arr[i - 1];

        if (diff[i - 1] < cur_def && cur_def < diff[i + 2] && arr[i - 1] < arr[i + 1]) {
            valid &= true;
        } else {
            valid &= false;
        }
        ans.push_back(valid);
    }

    // Check validity for the last element (special case)
    ans.push_back(pre_valid[n - 2]);

    // cout << pre_valid << suf_valid;
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
    }
    return 0;
}