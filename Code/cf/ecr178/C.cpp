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
    string str;
    cin >> str;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            a.push_back(i + 1);
        } else {
            b.push_back(i + 1);
        }
    }
    if (n == 2) {
        if (str[0] == 'A') {
            cout << "Alice";
        } else {
            cout << "Bob";
        }
        return;
    }
    bool same = str[0] == str.back();
    if (a.size() < 2) {
        cout << "Bob";
        return;
    } else if (b.size() < 2) {
        cout << "Alice";
        return;
    }
    if (same && str[0] == 'A') {
        cout << "Alice";
        return;
    } else if (same && str[0] == 'B') {
        cout << "Bob";
        return;
    }
    if (a.size() > 1 && (str[n - 1] == 'A' && str[n - 2] == 'A')) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }

    //no one has first and last card
    //both have atleast one card

    //so Alice has either 1 or N

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