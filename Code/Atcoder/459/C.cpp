#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


typedef long long ll;
#define mod 1000000007
vector<bool> prime;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
 
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
    int n, q;
    cin >> n >> q;
    vector<int> blocks(n, 0);
    ordered_set<pair<int, int>> os;
    for (int i = 0; i < n; i++) {
        os.insert({0, i});
    }
    while (q--) {
        int ch;
        cin >> ch;
        int x;
        cin >> x;
        x--;
        if (ch == 1) {
            os.erase({blocks[x], x});
            blocks[x]++;
            os.insert({blocks[x], x});
        } else {
            auto [mn, mn_idx] = *os.find_by_order(0);
            int atleast = mn + x + 1;
            int smaller = os.order_of_key({atleast, 0});
            cout << n - smaller << "\n";
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