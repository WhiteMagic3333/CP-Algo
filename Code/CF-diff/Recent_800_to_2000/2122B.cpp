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
    //12:22 (i am stuck at 12:30 for solving and implementing these)
    //some has extra 0's
    //some has extra 1's
    //remove those that have equal
    //guaranteed, in total we have sufficient zeroes and sufficient ones
    //also when we remove zeroes we can place them exactly where they are needed
    //both within same array and another group
    //take the piles with extra ones
    //remove those extra ones and give them to those who need it,
    //while doing so also find those that have extra zeroes they are fixed as well, finally
    //count extra ones
    int n;
    cin >> n;
    ll extra_zeroes = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b > d) { //we have extra ones
            ans += a + (b - d);
        } else if (a > c) {
            ans += a - c;
        }
        //add in ds
    }
    cout << ans;
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