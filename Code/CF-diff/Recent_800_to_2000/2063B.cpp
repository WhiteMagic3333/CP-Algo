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
{   //12:30 with wrong answer
    //huh, almost thought of the solution,
    //I hurry and get the final idea wrong, or doesnt prove and polish the idea
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    int k = r - l + 1;
    vector<int> arr(n), a, b;
    cin >> arr;
    for (int i = 0; i < n; i++) {
        if (i <= r) {
            a.push_back(arr[i]);
        }
        if (i >= l) {
            b.push_back(arr[i]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < k; i++) {
        s1 += a[i];
        s2 += b[i];
    }
    cout << min(s1, s2);
    
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