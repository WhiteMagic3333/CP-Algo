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

vector<array<int, 2>> ans;

void custom_sort(vector<int> &arr, int op) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int idx = i, mn = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < mn) {
                mn = arr[j];
                idx = j;
            }
        }
        if (idx != i) {
            for (int j = idx - 1; j >= i; j--) {
                ans.push_back({op, j});
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            ans.push_back({3, i});
            swap(a[i], b[i]);
        }
    }
    //sort a
    custom_sort(a, 1);
    custom_sort(b, 2);
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i[0] << " " << i[1] + 1 << "\n";
    }
    ans.clear();
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