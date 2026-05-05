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
    //do not touch the keyboard unless whole logic is clear
    //pre suf
    //took too long
    //yet again first got confident with the solution
    //and started implmeneting an unproven solution
    //prove your solution first
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cur = str[0] == '1';
    int changes = str[0] == '1';
    for (int i = 0; i < n; i++) {
        cur++;
        if (i > 0 && str[i] != str[i - 1]) {
            cur++;
            changes++;
        }
    }
    if (changes == 2) {
        cur--;
    } else if (changes > 2) {
        cur -= 2;
    }
    cout << cur;
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