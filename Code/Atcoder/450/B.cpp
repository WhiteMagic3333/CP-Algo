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
    int n;
    cin >> n;
    map<pair<int, int>, long long> cost;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int c;
            cin >> c;
            cost[{i, j}] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            for (int k = i + 1; k < j; k++) {
                if (cost[{i, k}] + cost[{k, j}] < cost[{i, j}]) {
                    cout << "Yes";
                    return;
                }
            }
        }
    }
    cout << "No";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}