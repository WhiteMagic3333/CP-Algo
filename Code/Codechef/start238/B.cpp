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
    int n, m;
    cin >> n >> m;
    if (n % 3 != 2) {
        cout << "-1";
        return;
    }
    //1
    //0 nope
    //2
    //0 x x 0
    //0 1 1 0
    //3
    //0 x x x 0
    //nope
    //4
    //0 M - 1 M - 1 0 1 1 0 M - 1 M - 1
    for (int i = 0; i * 3 < n; i++) {
        if (i % 2) {
            cout << m - 1 << " " << m - 1 << " ";
        } else {
            cout << "1 1 ";
        }
        if ((i + 1) * 3 < n) {
            cout << "0 ";
        }
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
        cout << "\n";
    }
    return 0;
}