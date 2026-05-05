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
    return out;
}
 
void solve()
{   //took 16 min but was a fun creative problem
    //took long to think
    //should implement first in mind before writing
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    //so shorter + 2 * equal >= larger
    int mx_idx = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (arr[i] == arr[i + 1]) {
            mx_idx = max(mx_idx, i);
        }
    }
    if (mx_idx == -1) {
        cout << "-1";
        return;
    }
    ll prev = 0;
    for (int i = 0; i < n; i++) {
        if (i == mx_idx || i == mx_idx + 1) {
            continue;
        }
        if (prev != 0 && prev + 2 * arr[mx_idx] > arr[i]) {
            cout << prev << " " << arr[mx_idx] << " " << arr[mx_idx] << " " << arr[i];
            return;
        }
        prev = arr[i];
    }
    cout << "-1";
    return;
    //min diff
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