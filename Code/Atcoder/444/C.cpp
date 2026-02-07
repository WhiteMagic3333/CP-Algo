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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    map<int, int> freq;
    for (auto i : arr) {
        freq[i]++;
    }
    //check last
    bool ok = true;
    int v = arr.back();
    for (auto i : arr) {
        if (i == v) {
            continue;
        }
        int rem = v - i;
        if (rem == i) {
            if (freq[i] % 2) {
                ok = false;
            }
        } else {
            if (freq[i] != freq[rem]) {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << v << " ";
    }
    v = arr.back() + arr.front();
    ok = true;
    for (auto i : arr) {
        if (i == v) {
            continue;
        }
        int rem = v - i;
        if (rem == i) {
            if (freq[i] % 2) {
                ok = false;
            }
        } else {
            if (freq[i] != freq[rem]) {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << v << " ";
    }

} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}