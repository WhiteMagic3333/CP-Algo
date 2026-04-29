#include <numeric>
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
{   //took too long
    //make more diagrams for these type of problems to get more clarity
    //like here make diagrams of what happens with 0, 1 pari 1 1 pair 02 pari and 2 2 pair and then analyze
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    cin >> arr;
    vector<int> f(3, 0);
    for (auto i : arr) {
        f[i]++;
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum > x) {
        cout << arr;
        return;
    }
    if (sum == x) {
        cout << "-1";
        return;
    }
    int d = x - sum;
    if (d == 1) {
        while (f[0]--) {
            cout << "0 ";
        }
        while (f[2]--) {
            cout << "2 ";
        }
        while (f[1]--) {
            cout << "1 ";
        }
        return;
    }
    cout << "-1";
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