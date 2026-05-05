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
{   //draw test cases in this difficulty 
    int n;
    cin >> n;
    string x;
    cin >> x;
    if (n % 2) {
        if (x[0] == 'b') {
            cout << "No";
            return;
        }
    }
    //now we either have abab or baba, both as same
    //at even length we can choose any
    //at odd length we must not choose what we previously chose
    int len = n - 1;
    for (int i = 1; i < n; i++) {
        if (len % 2) {
            if (x[i] != '?' && x[i - 1] != '?') {
                if (x[i] == x[i - 1]) {
                    cout << "No";
                    return;
                }
            }
        }
        len--;
    }
    cout << "Yes";
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