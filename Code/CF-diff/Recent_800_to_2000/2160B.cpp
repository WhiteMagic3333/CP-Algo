#include <unordered_map>
#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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

    //got stuck greed math 30 + mins
    int n;
    cin >> n;
    vector<ll> b(n);
    cin >> b;

    //b[i + 1] - b[i] = 1 additional value from new set arr[i], then in how many subarrays does it increase
    //b[i + 1] - b[i] = 1 + no of subsets that does not contain new value

    vector<int> ans(1);
    int last = 1;
    ans[0] = 1;
    last++;
    int subsets = 1; 
    for (int i = 1; i < n; i++) {
        int add_to_subsets = b[i] - b[i - 1] - 1;
        if (add_to_subsets == subsets) {
            ans.push_back(last);
            last++;
        } else {
            int freq = subsets - add_to_subsets;
            ans.push_back(ans[freq - 1]);
        }
        subsets++;
    }
    cout << ans;
}

int main() {
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