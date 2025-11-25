#include <algorithm>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_map>
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



map<tuple<string, int, int>, pair<int, int>> ans;

pair<int, int> get_ab(string a, string b) {
    int ac = 0, bc = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ac++;
        }
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (i == j) {
                continue;
            }
            if (a[i] == b[j]) {
                b[j] = '0';
                bc++;
                break;
            }
        }
    }
    return {ac, bc};
}

unordered_map<string, vector<string>> permu;

void pre(string cur) {
    string cpy = cur;
    permu[cpy].push_back(cur);
    while (next_permutation(cur.begin(), cur.end())) {
        permu[cpy].push_back(cur);
    }
}
 
void solve()
{
    string n;
    int j, k;
    cin >> n >> j >> k;
    auto [a, b] = get_ab(permu[n][j - 1], permu[n][k - 1]); 
    // cout << permu[n][j - 1] << " " << permu[n][k - 1] << "\n";
    cout << a << "A" << b << "B";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> cur = {"12","123","1234"};
    for (auto i : cur) {
        pre(i);
    }
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}