#include <unordered_map>
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
    vector<vector<int>> type(n, vector<int> (m, 0));
    for (auto &row : type) {
        cin >> row;
    }
    unordered_map<int, vector<int>> row, col; //row and col for same type
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[type[i][j]].push_back(i);
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col[type[i][j]].push_back(j);
        }
    }
    long long ans = 0;
    for (auto &[type, arr] : row) {
        int N = arr.size();
        for (int i = 0; i < N; i++) {
            ans += arr[i] * (2LL * i - N + 1);
        }
    }
    for (auto &[type, arr] : col) {
        int N = arr.size();
        for (int i = 0; i < N; i++) {
            ans += arr[i] * (2LL * i - N + 1);
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