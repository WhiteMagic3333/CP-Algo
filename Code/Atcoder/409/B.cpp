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

bool check(int x, vector<int> &arr) {
    int times = 0;
    for (auto i : arr) {
        if (i >= x) {
            times++;
        }
    }
    return times >= x;
}

int val(int x, vector<int> &arr) {
    int value = 0;
    for (int i : arr) {
        value += i >= x;
    }
    return value;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    int ans = 0;
    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid <= val(mid, arr)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}