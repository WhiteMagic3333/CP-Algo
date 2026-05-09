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
{
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end(), greater<ll> ());
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    //
    ll cross = sum / x; //it will cross x these many times
    ll ans = 0;
    vector<ll> answer;
    ll cur_sum = 0;
    int j = n - 1;
    for (int i = 0; i <= j; i++, cross--) {
        if (cross > 0) {
            ans += arr[i];
            while (cur_sum + arr[i] < x) {
                cur_sum += arr[j];
                answer.push_back(arr[j]);
                j--;
            }
            cur_sum = (cur_sum + arr[i]) % x;
            answer.push_back(arr[i]);
        } else {
            answer.push_back(arr[i]);
        }
    }
    // for (int i = 0, j = n - 1; i < j; i++) {

    // }
    cout << ans << "\n";
    if (answer.size() == 0) {
        answer = arr;
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
    }
    return 0;
}