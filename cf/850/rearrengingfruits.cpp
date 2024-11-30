#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<map>
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

long long minCost(vector<ll>& basket1, vector<ll>& basket2) {
        map<int, int> cnt;
        for (auto c: basket1) cnt[c]++;
        for (auto c: basket2) cnt[c]--;
        vector<int> last;
        for (auto &[k, v]: cnt) {
            // if v is odd, an even distribution is never possible
            if (v % 2) return -1;
            // the count of transferred k is |v|/2
            for (int i = 0; i < abs(v) / 2; ++i)
                last.push_back(k);
        }
        // find the min of two input arrays as the intermediate
        int minx = min(*min_element(basket1.begin(), basket1.end()),
                       *min_element(basket2.begin(), basket2.end()));
        // sort(last.begin(), last.end()) can be used as well
        nth_element(last.begin(), last.begin() + last.size() / 2, last.end());
        return accumulate(last.begin(), last.begin() + last.size() / 2, 0ll, 
            [&](long long s, int x) -> long long { return s + min(2*minx, x); }
        );
    }

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    cin >> a >> b;
    cout << minCost(a, b);
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