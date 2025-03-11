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
    return out;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(2 * n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    ll s1 = 0;
    for (int i = 0; i < n - 1; i++) {
        s1 += arr[i];
    }
    ll low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll half_sum = (s1 + mid);
        ll full_sum = sum + mid;
        if ((2 * half_sum) < full_sum) {
            low = mid + 1;
        } else if ((2 * half_sum) > full_sum) {
            high = mid - 1;
        } else {
            ans = mid;
            break;
        }
    }
    vector<ll> answer(2 * n + 1, 0);
    int i = 0, j = 2 * n - 1;
    for (int k = 0; k < 2 * n + 1; k++) {
        if (k % 2) {
            answer[k] = (i != n - 1) ? arr[i] : ans;
            i++;
        } else {
            answer[k] = arr[j];
            j--;
        }
    }
    cout << answer;
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