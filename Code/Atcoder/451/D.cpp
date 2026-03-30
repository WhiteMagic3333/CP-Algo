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
 
void pre(vector<int> &pow) {
    int cur = 1;
    int mx = 1e9;
    while (cur <= mx) {
        pow.push_back(cur);
        cur *= 2;
    }
}

void solve()
{
    vector<int> pow;
    pre(pow);
    vector<int> cur = pow;
    unordered_map<int, bool> vis;
    for (auto i : cur) {
        vis[i] = true;
    }
    for (int i = 0; i < cur.size(); i++) {
        for (int j = 0; j < pow.size(); j++) {
            string s1 = to_string(cur[i]);
            string s2 = to_string(pow[j]);
            if ((s1.length() + s2.length()) < 10) {
                int s3 = stoi(s1 + s2);
                if (!vis[s3]) {
                    cur.push_back(s3);
                    vis[s3] = true;
                }
            } else {
                break;
            }
        }
    }
    sort(cur.begin(), cur.end());
    int n;
    cin >> n;
    cout << cur[n - 1];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}