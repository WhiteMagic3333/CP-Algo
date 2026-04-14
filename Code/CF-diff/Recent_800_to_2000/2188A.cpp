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
    //should have taken lesser
    // 7:38 (800)
    // |p[n] - p[n - 1]| % (n - 1) == 0
    // one is n and other is 1
    // .......  3 n - 1 2 n 1
    int n;
    cin >> n;
    vector<int> arr(n);
    int last = n, first = 1;
    for (int i = n, j = 0; i > 0; i--, j++) {
        if (j % 2 == 0) {
            arr[i - 1] = first++;
        } else {
            arr[i - 1] = last--;
        }
    }
    cout << arr;
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