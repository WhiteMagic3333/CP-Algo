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
{   //took too long 21 mins, althought the problem seemed fairly easy, i felt sleepy and slow
    ll n, k;
    cin >> n >> k;
    // we can do RL or LR or UD DU or UUD but not n2 - 1
    vector<string> grid(n, string(n, 'U'));
    k = n * n - k; //k here is not allowed
    if (k == 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if (n <= k) {
        grid[0][0] = 'D';
        k -= n;
    } else if (k) {
        grid[n - k][0] = 'D';
        k = 0;
    }
    for (int i = 1; i < n && k; i++) {
        if (n <= k) {
            grid[0][i] = 'L';
            k -= n;
        } else if (k) {
            grid[n - k][i] = 'L';
            k = 0;
        }
    }
    for (auto &row : grid) {
        cout << row << "\n";
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
    }
    return 0;
}