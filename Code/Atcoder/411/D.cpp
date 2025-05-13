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
    int n, q;
    cin >> n >> q;
    int cnt = 1;
    vector<string> m(q + 1, "");
    m[0] = "";
    vector<vector<int>> arr(n + 1); //server at 0
    int server_size = 0, server = 0;
    for (int i = 0; i < q; i++) {
        int t, p;
        cin >> t >> p;
        if (t == 2) {
            string s;
            cin >> s;
            m[cnt] = s;
            arr[p].push_back(cnt);
            cnt++;
        } else if (t == 1) {
            is_
        } else if (t == 3) {
            server = p;
            server_size = arr[p].size();
        }
    }
    for (auto i : arr[n + 1]) {
        cout << m[i];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}