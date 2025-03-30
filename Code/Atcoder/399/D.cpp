#include <unordered_map>
#include <set>
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

void add(set<array<int, 2>> &s, int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    s.insert({a, b});
}

bool valid(int &cur, vector<int> &arr, vector<bool> &vis) {
    if (vis[cur]) {
        return false;
    }
    for (int i : arr) {
        if (cur == i && !vis[i]) {
            return true;
        }
    }
    return false;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    cin >> arr;
    vector<bool> vis(n + 1, false);
    unordered_map<int, vector<int>> neighbours;
    set<array<int, 2>> s;
    for (int i = 0; i < 2 * n; i++) {
        if (i != 0 && arr[i] == arr[i - 1]) {
            vis[arr[i]] = true;
        }
        if (i != (2 * n - 1) && arr[i] == arr[i + 1]) {
            vis[arr[i]] = true;
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (neighbours.count(arr[i]) == 0) {
            if (i != 0 && !vis[arr[i - 1]]) {
                neighbours[arr[i]].push_back(arr[i - 1]);
            }
            if (i != (2 * n - 1) && !vis[arr[i + 1]]) {
                neighbours[arr[i]].push_back(arr[i + 1]);
            }
        } else if (!vis[arr[i]]) {
            if (i != 0 && !vis[arr[i - 1]] && valid(arr[i - 1], neighbours[arr[i]], vis)) {
                add(s, arr[i - 1], arr[i]);
            }
            if (i != (2 * n - 1) && valid(arr[i + 1], neighbours[arr[i]], vis)) {
                add(s, arr[i + 1], arr[i]);
            }
        }
    }
    cout << s.size();
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
        cout << "\n";
    }
    return 0;
}