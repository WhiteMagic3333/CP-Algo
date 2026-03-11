#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <stack>
#include <set>
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
    multiset<int> s;
    int n, q;
    cin >> n >> q;
    vector<int> balls(n);
    cin >> balls;
    for (auto i : balls) {
        s.insert(i);
    }
    while (q--) {
        int sz;
        cin >> sz;
        stack<int> k;
        while (sz--) {
            int a;
            cin >> a;
            k.push(a);
            s.erase(s.find(balls[a - 1]));
        }
        cout << *(s.begin()) << "\n";
        while (k.size()) {
            s.insert(balls[k.top() - 1]);
            k.pop();
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}