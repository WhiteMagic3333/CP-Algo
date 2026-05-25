#include <algorithm>
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
    return out;
}
 
void solve()
{
    int n, x, y; 
    cin >> n >> x >> y;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> mid, border;
    for (int i = 1; i <= n; i++) {
        if (i <= x || i > y) {
            border.push_back(p[i]);
        } else {
            mid.push_back(p[i]);
        }
    }
    int mn = *min_element(mid.begin(), mid.end());
    for (int i = 1; i < mid.size(); i++) {
        if (mid[i] == mn) {
            reverse(mid.begin(), mid.begin() + i - 1);
            reverse(mid.begin() + i, mid.end());
            reverse(mid.begin(), mid.end());
            break;
        }
    }
    if (border.size()) {
        int i = 0;
        while (i < border.size() && border[i] < mid.front()) {
            i++;
        }
        for (int j = 0; j < i; j++) {
            cout << border[j] << " ";
        }
        for (auto j : mid) {
            cout << j << " ";
        }
        for (int j = i; j < border.size(); j++) {
            cout << border[j] << " ";
        }
    } else {
        cout << mid;
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