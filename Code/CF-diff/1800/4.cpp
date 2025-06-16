//2092D
#include <set>
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
        std::cout << x << '\n';
    return out;
}

vector<int> l = {'T', 'I', 'L'};

void fun(unordered_map<char, int> &m, unordered_map<char, int> &idx, char a, char c) {
    vector<int> ans;
    char b;
    for (auto ch : l) {
        if (ch != a && ch != c) {
            b = ch;
        }
    }
    idx[b] = idx[c];
    idx[c]++;
    ans.push_back(b);
    m[b]++;
    cout << ans.size() << "\n";
    cout << ans;
}
 
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    unordered_map<char, int> m, idx;
    m['T'] = m['I'] = m['L'] = 0;
    for (char ch : str) {
        m[ch]++;
    }
    if (max({m['T'], m['I'], m['L']}) == n) {
        cout << "-1\n";
        return;
    }
    //each element should come n times
    for (auto i : l) {
        for (auto j : l) {
            if (i == j) {
                continue;
            }
            for (int k = 1; k < n; k++) {
                if (str[k - 1] == i && str[k] == j) {
                    idx[i] = k - 1;
                    idx[j] = k;
                    fun(m, idx, i, j);
                    return;
                }
            }
        }
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