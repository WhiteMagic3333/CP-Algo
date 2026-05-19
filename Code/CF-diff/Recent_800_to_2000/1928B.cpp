#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <unordered_set>
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
{   //12 mins
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    unordered_set<int> s;
    for (auto i : arr) {
        s.insert(i);
    }
    vector<int> a;
    for (auto i : s) {
        a.push_back(i);
    }
    sort(a.begin(), a.end());
    int l = 0, r = 0, ans = 1;
    while (r < a.size()) {
        while (r < a.size() && a[l] + n > a[r]) {
            r++;
        }
        ans = max(ans, r - l);
        l++;
    }
    cout << ans;
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