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
    vector<int> arr(n);
    cin >> arr;
    vector<int> z;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            z.push_back(i + 1);
        }
    }
    if (z.size() == 0) {
        cout << 1 << "\n";
        cout << 1 << " " << n << "\n";
        return;
    } else if (z.size() == n) {
        cout << 3 << "\n";
        cout << n/2 + 1 << " " << n << "\n";
        cout << 1 << " " << n/2 << "\n";
        cout << 1 << " " << 2 << "\n";
    } else if (arr[0] != 0) {
        cout << 2 << "\n";
        cout << 2 << " " << n << "\n";
        cout << 1 << " " << 2 << "\n";
    } else if (arr.back() != 0) {
        cout << 2 << "\n";
        cout << 1 << " " << n - 1 << "\n";
        cout << 1 << " " << 2 << "\n";
    } else {
        cout << 3 << "\n";
        cout << 3 << " " << n << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
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