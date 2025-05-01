#include <algorithm>
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
    int old = 0;
    vector<int> arr;
    for (int j = 1; j <= 10; j++) {
        arr.push_back(j);
        set<int> ans;
        do {
            int cur = 0;
            for (int i = 0; i < arr.size(); i++) {
                cur += abs(arr[i] - (i + 1));
            }
            ans.insert(cur);
        }while (next_permutation(arr.begin(), arr.end()));
        cout << ans.size() << "|" << ans.size() - old << "\n";
        old = ans.size();
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}