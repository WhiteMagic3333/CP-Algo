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

bool both_pos(ll i, ll j) {
    if (i > 0 && j > 0) {
        return true;
    }
    return false;
}
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    cin >> arr;
    
    for (int i = 0; i < n; ++i) {
        int gt = 0;
        int st = 0;
        
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                gt++;
            } else if (arr[j] < arr[i]) {
                st++;
            }
        }
        
        cout << max(gt, st) << " ";
    }
    cout << "\n";
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
    }
    return 0;
}