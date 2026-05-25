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
{   //37 mins tough
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    cin >> a >> b;
    vector<int> fb(n + 1, 0), f(n + 1, 0), fa(n + 1, 0);
    for (auto i : b) {
        if (i != -1) {
            fb[i]++;
            if (fb[i] > 1) {
                cout << "No";
                return;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        fa[a[i]]++;
        if (b[i] != -1) {
            f[b[i]]++;
        }
    }
    for (int i = 0; i < k; i++) {
        if (fb[a[i]] && f[a[i]] == 0) {
            cout << "No";
            return; //not in range but in subarray
        }
        if (b[i] != -1 && fa[b[i]] == 0) {
            cout << "No";
            return;
        }
    }
    for (int i = k; i < n; i++) {
        //all values in b must exist in a
        //and all va

        int p_idx = i - k;
        fa[a[p_idx]]--;
        fa[a[i]]++;
        if (b[p_idx] != -1) {
            f[b[p_idx]]--;
            if (fa[b[p_idx]]) {
                cout << "No";
                return; //not in subarray of b but in a
            }
        }
        if (b[i] != -1) {
            f[b[i]]++;
            if (fa[b[i]] == 0) {
                cout << "No";
                return; //not in subarray of a but in b
            }
        }
        if ((fb[a[i]] && f[a[i]] == 0) || (f[a[p_idx]])) {
            cout << "No";
            return; //not in range but in subarray
        }
    }
    cout << "Yes";
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