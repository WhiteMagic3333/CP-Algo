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
{   //14 mins
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    int mex = 0;
    vector<bool> vis(n + 2, false);
    for (auto i : arr) {
        vis[i] = true;
        while (vis[mex]) {
            mex++;
        }
    }
    fill(vis.begin(), vis.end(), false);
    int m1 = 0, m2 = 0;
    int l = -1, r = n + 1;
    for (int left = 0; left < n; left++) {
        vis[arr[left]] = true;
        while (vis[m1]) {
            m1++;
        }
        if (m1 == mex) {
            l = left;
            break;
        }
    }
    fill(vis.begin(), vis.end(), false);
    for (int right = n - 1; right >= 0; right--) {
        vis[arr[right]] = true;
        while (vis[m2]) {
            m2++;
        }
        if (m2 == mex) {
            r = right;
            break;
        }
    }
    if (l < r) {
        cout << "2\n1 " << l + 1 << "\n" << l + 2 << " " << n;
    } else {
        cout << "-1";
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
        cout << "\n";
    }
    return 0;
}