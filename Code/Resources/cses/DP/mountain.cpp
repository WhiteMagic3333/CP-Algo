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
 
const int N = 200000;
const int L = 20;

vector<int> x(N);
vector<vector<array<int, 2>>> table(N, vector<array<int, 2>> (L, {0, 0}));

// Returns the minimum value in range [l, r)
// int get_min(int l, int r) {
//     // __lg(x) returns the base-2 logarithm of x, rounded down.
//     // With it, we'll figure out the largest power of two
//     // that is not larger than the length of the query.
//     int i = __lg(r - l);
//     return min(table[l][i], table[r - (1 << i)][i]);
// }

array<int, 2> get_max_with_idx(array<int, 2> &a, array<int, 2> &b) {
    if (a[0] == b[0]) {
        return a[1] < b[1] ? a : b;
    } else if (a[0] > b[0]) {
        return a;
    }
    return b;
}

array<int, 2> get_max(int l, int r) {
    int i = __lg(r - l);
    return get_max_with_idx(table[l][i], table[r - (1 << i)][i]);
}

int rec(int l, int r, int prev) {
    if (l > r) {
        return 0;
    } else if (l == r) {
        return prev != get_max(l, r)[0];
    }
    array<int, 2> mx = get_max(l, r);
    cout << mx[0] << " " << mx[1] << " (" << l << "," << mx[1] - 1 << ") (" << mx[1] + 1 << "," << r << ")\n";
    int add = (prev != mx[0]);
    return add + max(rec(l, mx[1] - 1, mx[0]), rec(mx[1] + 1, r, mx[0]));
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    for (int i = 0; i < n; i++) {
        table[i][0][0] = arr[i];
        table[i][0][1] = i;
    }
    for (int j = 0; (1 << j) < n; ++j) {
        for (int i = 0; i + (1 << j) < n; ++i) {
            table[i][j + 1] = get_max_with_idx(table[i][j], table[i + (1 << j)][j]);
        }
    }
    // cout << rec(0, n - 1, 1e9 + 1);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}