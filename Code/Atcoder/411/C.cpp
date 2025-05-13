#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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

void add(set<pair<int, int>> &s, pair<int, int> &cur) {

}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 2, 0);
    int ans = 0;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        x[a] ^= 1;
        if (x[a]) {
            if (x[a - 1] && x[a + 1]) {
                ans--;
            } else if (x[a - 1] || x[a + 1]) {
                //eat five star do nothing
            } else {
                ans++;
            }
        } else {
            if (x[a - 1] && x[a + 1]) {
                ans++;
            } else if (x[a - 1] || x[a + 1]) {
                //eat five star do nothing
            } else {
                ans--;
            }
        }
        cout << ans << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}