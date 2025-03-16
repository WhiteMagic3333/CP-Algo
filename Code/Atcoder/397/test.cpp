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

int prod(int i) {
    int p = 1;
    while(i) {
        int d = i % 10;
        p *= d;
        i /= 10;
    }
    return p;
}

int sum(int i) {
    int p = 0;
    while(i) {
        int d = i % 10;
        p += d;
        i /= 10;
    }
    return p;
}
 
void solve()
{
    int r = 1000;
    for (int i = 1; i < r; i++) {
        int p = prod(i);
        int s = sum(i);
        if (p % s == 0) {
            cout << i << "\n";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}