#include <unordered_map>
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
{   //for odd freq element
    //no matter how you split, answer will always inc by 1

    // so main is even freq
    // if even is 4x then half is also even
    // or even is 2x
    // if 2x then keep half
    // if 4x then 2x - 1 and 2x + 1
    // count 4x and 2x
    // if 4x == 2n then ans -= 2;k
    //took too long
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    cin >> arr;
    unordered_map<int, int> f;
    for (auto i : arr) {
        f[i]++;
    }
    int ans = 0;
    int z = 0, f4;
    for (auto [val, fr] : f) {
        if (fr % 2) {
            z++;
        } else {
            ans += 2;
            if (fr % 4 == 0) {
                f4++;
            }
        }
    }
    ans += z;
    if (z == 0 && f4 % 2) {
        ans -= 2;
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