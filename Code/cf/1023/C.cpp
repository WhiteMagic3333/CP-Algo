#include <numeric>
#include <vector>
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

long long mss(vector<ll> &arr, int i, int j) {
    ll ans = arr[i]; 
    ll sum = arr[i];  
    for (int p = i + 1; p < j; p++) {
        sum = max(arr[p], sum + arr[p]); 
        ans = max(sum, ans);
    }
    return ans;
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<ll> arr(n);
    cin >> arr;
    ll mssp; //maximum subarray sum per partition
    if (count(str.begin(), str.end(), '0') == n) {
        cout << "Yes\n";
        cout << k << " ";
        for (int i = 1; i < n; i++) {
            cout << "0 ";
        }
        return;
    } else if (count(str.begin(), str.end(), '0') == 0) {
        mssp = mss(arr, 0, n);
        if (mssp == k) {
            cout << "Yes\n";
            cout << arr;
        } else {
            cout << "No";
        }
        return;
    }
    int i = 0;
    ll mx_mssp = -1e18;
    while (i < n) {
        while (i < n && str[i] == '0') {
            i++;
        }
        int j = i + 1;
        while (j < n && str[j] == '1') {
            j++;
        }
        mssp = mss(arr, i, j);
        if (mssp > k) {
            cout << "No";
            return;
        }
        mx_mssp = max(mx_mssp, mssp);
        i = j;
    }
    if (mx_mssp == k) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                cout << -1e15 << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        return;
    } else {
        //two consec
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                arr[i] = -1e18;
            }
        }
        
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