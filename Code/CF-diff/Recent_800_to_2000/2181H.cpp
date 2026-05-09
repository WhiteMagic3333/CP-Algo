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

    //what does gcd(l, n) give
    //the largest lenght that divides both
    //we need to maximize parts if I take lenght, then
    //it minimizes parts
    //the gcd(l, n) max parts we can divide l into

    ll l, b, h;
    cin >> l >> b >> h;
    ll n;
    cin >> n;
    ll rem = l;
    rem %= n;
    rem *= b;
    rem %= n;
    rem *= h;
    rem %= n;
    if (rem != 0) {
        cout << "-1";
        return;
    }
    ll N = n;
    ll pl = __gcd(n, l);
    n /= pl;
    ll l1 = l / pl;
    ll pb = __gcd(b, n);
    n /= pb;
    ll b1 = b / pb;
    ll ph = __gcd(h, n);
    ll h1 = h / ph;
    //misunderstood the derivation
    //derived wrong meanings
    cout << pl - 1 << " " << pb - 1 << " " << ph - 1;


}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}