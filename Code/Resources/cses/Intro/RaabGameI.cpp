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
    if ((a + b) > n || max(a, b) == n) {
        cout << "NO";
        return;
    } else if ((a + b) == n) { //no draws
        cout << "YES\n";
        //right shift a
        int start_a = n - a;
        for (int i = 0; i < n; i++) {
            cout << (start_a + i) % n + 1 << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
    } else if (max(a, b) == 0) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
    }  else { //we have draws
        int draws = n - (a + b);
        int rem = n - draws;
        if (rem == a || rem == b) {
            cout << "NO";
            return;
        }
        cout << "YES\n";
        int N = n;
        n = rem;
        int start_a = n - a;
        for (int i = 0; i < n; i++) {
            cout << (start_a + i) % n + 1 << " ";
        }
        for (int i = n + 1; i <= N; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        for (int i = n + 1; i <= N; i++) {
            cout << i << " ";
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