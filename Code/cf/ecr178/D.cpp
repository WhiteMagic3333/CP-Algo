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
vector<int> primes;
 
void sieve(ll n)
{
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i);
            if (i * i <= n) {
                for (ll j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
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
    vector<ll> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end(), greater<ll> ());
    int j = 0;
    ll coins = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= primes[j]) {
            coins += arr[i] - primes[j];
            j++;
        } else {
            if ((arr[i] + coins) >= primes[j]) {
                coins -= (primes[j] - arr[i]);
                j++;
            } else {
                ans = n - i;
                break;
            }
        }
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    sieve(6e6);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}