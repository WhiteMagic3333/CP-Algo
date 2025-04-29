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

const int mx_size = 1;
vector<vector<int>> nxt(mx_size, vector<int> (26, 0));
vector<int> y_cnt(mx_size, 0);

int N = 0, z = 0, y = 0;

bool inserted(string &str, int &node) {
    for (char &ch : str) {
        if (y_cnt[nxt[node][ch - 'a']] == -1) {
            return false;
        } else if (nxt[node][ch - 'a'] == 0) {
            nxt.emplace_back(vector<int> (26, 0));
            y_cnt.push_back(0);
            nxt[node][ch - 'a'] = ++N;
        }
        node = nxt[node][ch - 'a'];
    }
    return true;
}

void add_in_x() {
    string str;
    cin >> str;
    int node = 0;
    if (!inserted(str, node)) {
        return;
    }
    int rem = y_cnt[node];
    y_cnt[node] = -1;
    node = 0;
    for (auto &ch : str) {
        y_cnt[node] -= rem;
        node = nxt[node][ch - 'a'];
    }
    z += rem;
}

void add_in_y() {
    string str;
    cin >> str;
    int node = 0;
    if (!inserted(str, node)) {
        z++;
        return;
    }
    node = 0;
    y_cnt[node]++;
    for (auto &ch : str) {
        node = nxt[node][ch - 'a'];
        y_cnt[node]++;
    }
}

void solve()
{
    int q;
    cin >> q;
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            add_in_x();
        } else{
            y++;
            add_in_y();
        }
        cout << y - z << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}