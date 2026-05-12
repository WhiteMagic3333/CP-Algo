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
    //cyclic shift leetcode idea
    //ik that in 3 steps i can cyclically shift right
    //an array (1, n) (1, k) (k + 1, n)
    //can we do it in 2
    //5 4 3 2 1
    //1 5 4 3 2 ([1] [2 3 4 5])
    //2 1 5 4 3 ([1 2] [3 4 5])
    //this is a very clever idea
    //the generally shift requires 3 moves
    //but we reverse the first and then 2 moves each row
    // 3 2 1
    // 1 3 2
    // 2 1 3

    int n;
    cin >> n;
    cout << 2 * n - 1 << "\n";
    cout << "1 1 " << n << "\n";
    for (int i = 1; i < n; i++) {
        cout << i + 1 << " 1 " << i << "\n";
        cout << i + 1 << " " << i + 1 << " " << n << "\n";
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