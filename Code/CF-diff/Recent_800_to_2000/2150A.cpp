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
    return out;
}
 
void solve()
{   //should havve taken 15 mins took 40 
    int n, m;
    cin >> n >> m;
    string query;
    cin >> query;
    set<int> b;
    int cell;
    for (int i = 0; i < m; i++) {
        cin >> cell;
        b.insert(cell);
    }
    cell = 1;
    for (int i = 0; i < n; i++) {
        if (i != 0 && query[i - 1] == 'B') {
            while (b.find(cell) != b.end()) {
                cell++;
            }
        }
        char ch = query[i];
        if (ch == 'A') {
            cell++;
        } else {
            cell++;
            while (b.find(cell) != b.end()) {
                cell++;
            }
        }
        b.insert(cell);
    }
    cout << b.size() << "\n";
    if (b.size()) {
        for (auto i : b) {
            cout << i << " ";
        }
        cout << "\n";
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