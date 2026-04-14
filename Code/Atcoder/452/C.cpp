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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int m;
    cin >> m;
    vector<string> words(m);
    for (auto &word : words) {
        cin >> word;
    }
    // vector<vector<string>> word_of_len(11);
    // for (auto word : words) {
    //     word_of_len[word.size()].push_back(word);
    // }
    //for each word length mark all the chars that are possible
    vector<vector<vector<bool>>> vis(11, vector<vector<bool>> (11, vector<bool> (26, false)));
    for (auto word : words) {
        int len = word.length();
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            vis[len][i][ch - 'a'] = true;
        }
    }
    for (auto word : words) {
        bool ok = true;
        int len = word.length();
        if (len != n) {
            ok = false;
        } else {
            for (int i = 0; i < n; i++) {
                if (!vis[a[i]][b[i] - 1][word[i] - 'a']) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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