#include <iomanip>
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
    vector<vector<int>> arr(3, vector<int> (6));
    for (auto &row : arr) {
        cin >> row;
    }
    vector<vector<int>> ss;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                vector<int> cur = {arr[0][i], arr[1][j], arr[2][k]};
                sort(cur.begin(), cur.end());
                ss.push_back(cur);
            }
        }
    }
    int cnt = 0;
    for (auto cur : ss) {
        if (cur[0] == 4 && cur[1] == 5 && cur[2] == 6) {
            cnt++;
        }
    }
    double a = cnt, b = ss.size();
    cout << setprecision(10) << (a / b);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}