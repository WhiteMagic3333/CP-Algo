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
    int n, l;
    cin >> n >> l;
    vector<long long> d(n - 1);
    cin >> d;
    vector<long long> arr(l, 0);
    arr[0] = 1;
    int idx = 0;
    for (int i = 0; i < n - 1; i++) {
        idx += d[i];
        idx %= l;
        arr[idx]++;
    }
    if (l % 3) {
        cout << "0";
        return;
    } else {
        long long ans = 0;
        int N = l / 3;
        for (int i = 0; i < N; i++) {
            ans += arr[i] * arr[i + N] * arr[i + N + N];
        }
        cout << ans;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}