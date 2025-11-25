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
    int N;
    long long X, Y;
    cin >> N >> X >> Y;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long d = Y - X;

    long long g = std::gcd(d, X);

    for (int i = 0; i < N; i++) {
        if ((A[0] - A[i]) % (d / g) != 0) {
            cout << -1 << "\n"; 
            return;
        }
    }

    long long k_num = X / g;  
    long long k_den = d / g;

    long long L1_low = 0;
    long long L1_high = 1e18;

    for (int i = 0; i < N; i++) {
        long long diff = (A[0] - A[i]) / k_den; 
        long long Ti = k_num * diff;      
        L1_low = max(L1_low, -Ti);
        L1_high = min(L1_high, A[i] - Ti);
    }

    if (L1_low > L1_high) {
        cout << -1 << "\n";
        return;
    }

    long long L1 = L1_high;

    long long total = 0;
    for (int i = 0; i < N; i++) {
        long long diff = (A[0] - A[i]) / k_den;
        long long Ti = k_num * diff;
        long long Li = L1 + Ti;
        total += Li;
    }

    cout << total << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}