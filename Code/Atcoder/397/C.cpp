#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<unordered_map>
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
    vector<int> arr(n);
    cin >> arr;
    unordered_map<int, int> m1, m2;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        if (m1[arr[i]] == 0) {
            d1++;
        }
        m1[arr[i]]++;
    }
    int ans = d1;
    for (int i = 0; i < n; i++) {
        m1[arr[i]]--;
        if (m1[arr[i]] == 0) {
            d1--;
        }
        m2[arr[i]]++;
        if (m2[arr[i]] == 1) {
            d2++;
        }
        ans = max(ans, d1 + d2);
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}