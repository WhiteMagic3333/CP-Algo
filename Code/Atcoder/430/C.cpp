#include <algorithm>
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
    int n, A, B;
    cin >> n >> A >> B;
    string str;
    cin >> str;
    vector<int> pa(n, 0), pb(n, 0);
    if (str[0] == 'a') {
        pa[0]++;
    } else {
        pb[0]++;
    }
    for (int i = 1; i < n; i++) {
        if (str[i] == 'a') {
            pa[i]++;
        } else {
            pb[i]++;
        }
        pa[i] += pa[i - 1];
        pb[i] += pb[i - 1];
    }
    //a's count >= A
    //b's count < B
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int pre_a = (i == 0) ? 0 : pa[i - 1];
        int pre_b = (i == 0) ? 0 : pb[i - 1];
        int l = lower_bound(pa.begin(), pa.end(), A + pre_a) - pa.begin();
        int r = lower_bound(pb.begin(), pb.end(), B + pre_b) - pb.begin();
        ans += max(0LL, 1LL* (r - l));
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