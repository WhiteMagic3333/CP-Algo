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

vector<ll> cubes;

void pre() {
    cubes.push_back(1);
    cubes.push_back(2);

    for (int i = 2; i < 11; i++) {
        cubes.push_back(cubes[i - 1] + cubes[i - 2]);
    }
}

bool check(int l, int b, int s1, int s2) {
    if (min(l, b) < s1) {
        return false;
    }
    if (max(l, b) - s1 < s2) {
        return false;
    }
    return true;
}

 
void solve()
{   //unique idea fibonacci squares
    ll n, m;
    cin >> n >> m;
    int s1 = cubes[n - 1], s2 = cubes[n - 2];
    for (int i = 0; i < m; i++) {
        int w, l, h;
        cin >> w >> l >> h;
        if (min({w, l, h}) < s1) {
            cout << "0";
        } else if (check(w, l, s1, s2) || check(w, h, s1, s2) || check(l, h, s1, s2)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    pre();
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}