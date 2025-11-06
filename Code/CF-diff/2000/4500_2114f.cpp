#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_map>
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

int fun(long long f, int k) {
    if (f == 1) {
        return 0;
    }
    vector<int> div;
    for (int i = 1; i * i <= f; i++) {
        if (f % i == 0) {
            div.push_back(i);
            if (i * i != f) {
                div.push_back(f / i);
            }
        }
    }
    sort(div.begin(), div.end());
    int n = div.size();
    vector<int> dp(n, 100);//dp[i] = min no of factors of div[i]
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (div[i] / div[j] > k) {
                break;
            }
            if (div[i] % div[j] == 0) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1] == 100 ? -1 : dp[n - 1];
}
 
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    int g = __gcd(x, y);
    int a1 = fun(x / g, k);
    int a2 = fun(y / g, k);
    if (a1 == -1 || a2 == -1) {
        cout << "-1";
        return;
    }
    cout << a1 + a2;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve(1e3 + 1);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
 
    return 0;
}