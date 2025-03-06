#include <sys/types.h>
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
    string a, b;
    cin >> a >> b;
    int c1 = 0, c0 = 0, cop = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '0') {
                c0++;
            } else {
                c1++;
            }
        } else {
            cop++;
        }
    }
    if (c1 % 2 == 0 && c0 % 2 == 0) {
        cout << "Yes";   
    } else if (c1 % 2 == 0 || c0 % 2 == 0) {
        if (cop % 2 == 0) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else {
        cout << "No";
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



c = 10;

k = 2

TC for b = 3 + 4 + 5 = 12

f[B] = 3;

ap_sum(f[b] + old_k) - f(old_k)

1 + 2 + 3 + 4 + 5 - (1 + 2)


AABBB




Cost-> 



C, (C + k)


C

k + C






a , b

a & b = N


new <= M

a = 01111
b = 01011
N = 000000000000001011
x = 000000000000010000
    0000000000000template <typename _InputIter>



S[0] =01011
S[1] =01111
S[2] =11011


