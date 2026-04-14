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

vector<int> parent, comp_sz;
int total_comp, largest_comp_sz;

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (comp_sz[a] < comp_sz[b]) {
            swap(a, b);
        }
        comp_sz[a] += comp_sz[b];
        parent[b] = a;
        largest_comp_sz = max({largest_comp_sz, comp_sz[a]});
        total_comp--;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    vector<vector<int>> edges(m, vector<int> (2));
    comp_sz.resize(n, 1);
    total_comp = n, largest_comp_sz = 1;
    for (auto &edge : edges) {
        cin >> edge;
        edge[0]--;
        edge[1]--;
    }
    iota(parent.begin(), parent.end(), 0LL);
    for (auto edge : edges) {
        unite(edge[0], edge[1]);
        cout << total_comp << " " << largest_comp_sz << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}