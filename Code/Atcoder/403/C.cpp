#include<bits/stdc++.h>
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
    int n, m, q;
    cin >> n >> m >> q;
    unordered_set<int> all;
    set<pair<int, int>> cur;
    while (q--) {
        int ch, x, y;
        cin >> ch >> x;
        if (ch == 2) {
            all.insert(x);
        } else {
            cin >> y;
            if (ch == 1) {
                cur.insert({x, y});
            } else {
                if (all.find(x) != all.end() || cur.find({x, y}) != cur.end()) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
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