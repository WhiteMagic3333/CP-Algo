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

int ans = 0, n, m;
vector<string> grid(n);

bool valid(int h1, int h2, int i, int j) {
    if (i + h1 - 1 >= n || j + h2 - 1 >= m) {
        return false;
    }
    for (int x = 0; x < h1; x++) {
        for (int y = 0; y < h2; y++) {
            int rev_i = i + h1 - x - 1;
            int rev_j = j + h2 - y - 1;
            if (grid[x + i][y + j] != grid[rev_i][rev_j]) {
                return false;
            }
        }
    }
    return true;
}
 
void solve()
{
    cin >> n >> m;
    grid = vector<string> (n);
    for (auto &row : grid) {
        cin >> row;
    }
    for (int h1 = 1; h1 <= 10; h1++) {
        for (int h2 = 1; h2 <= 10; h2++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (valid(h1, h2, i, j)) {
                        ans++;
                    }
                }
            }
        }
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