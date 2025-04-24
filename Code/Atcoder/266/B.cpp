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
    long long int n;
    cin >> n;
    long long int x;

    if (n < 0) {
        if (n % 998244353 == 0)
            cout << "0";
        else {
            n *= -1LL;
            x = n / 998244353;
            ++x;
            long long int t = 998244353 * x;
            cout << t - n;
        }
    }
    else if (n >= 0 && n < 998244353) {
        cout << n;
    }
    else {
        x = n % 998244353;
        cout << x;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}