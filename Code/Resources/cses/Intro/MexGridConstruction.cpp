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
    vector<vector<int>> ans(n, vector<int> (n, 0));
    vector<bool> pres;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int mex = 0;
            pres = vector<bool> (102, false);
            for (int i2 = 0; i2 < i; i2++) {
                pres[ans[i2][j]] = true;
            }
            for (int j2 = 0; j2 < j; j2++) {
                pres[ans[i][j2]] = true;
            }
            while (pres[mex]) {
                mex++;
            }
            ans[i][j] = mex;
        }
    }
    for (auto &row : ans) {
        cout << row;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}