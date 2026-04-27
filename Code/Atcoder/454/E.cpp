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
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2) {
        cout << "No";
        return;
    }
    if ((a + b) % 2 == 0) {
        cout << "No";
        return;
    }
    string dir = "LRUD";
    vector<array<int, 2>> dxy = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    cout << "Yes\n";
    string ans = "";
    for (int i = 0; i < n; i += 2) {
        if (a == i || (a - 1) == i) {

        } else {
            //RRRDLLLDRRR
            for (int j = 1; j < n; j++) {
                ans.push_back("R");
            }
            ans.push_back("D");
            for (int j = 1; j < n; j++) {
                ans.push_back("L");
            }
        }
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