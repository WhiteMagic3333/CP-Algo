#include <set>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#define all(a) a.begin(),a.end() //imp
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

long long mergeSort(vector<int>& a, vector<int>& temp, int l, int r) { //returns inv count
    if (l >= r) return 0;
    int m = (l + r) / 2;
    long long inv = 0;
    inv += mergeSort(a, temp, l, m);
    inv += mergeSort(a, temp, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++], inv += m - i + 1;
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = temp[i];
    return inv;
}

long long inversion_count(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        if (i % 2) {
            b.push_back(cur);
        } else {
            a.push_back(cur);
        }
    }

    bool not_sorted = (inversion_count(a) % 2) != (inversion_count(b) % 2);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            ans.push_back(b[i / 2]);
        } else {
            ans.push_back(a[i / 2]);
        }
    }
    if (not_sorted) {
        swap(ans[n - 1], ans[n - 3]);
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
    }
    return 0;
}