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
    int n, R;
    cin >> n >> R;
    vector<int> door(n + 2, 1);
    for (int i = 1; i <= n; i++) {
        cin >> door[i];
    }
    int l = 0, r = n + 1;
    for (int i = 1; i <= n && door[i] == 1; i++) {
        l = i;
    }
    for (int i = n; i > 0 && door[i] == 1; i--) {
        r = i;
    }
    int ans = 0;
    for (int i = R; i > l; i--) {
        ans += 1 + door[i];
    }
    for (int i = R + 1; i < r; i++) {
        ans += 1 + door[i];
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