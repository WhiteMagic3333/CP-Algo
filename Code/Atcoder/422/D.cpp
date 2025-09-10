#include <algorithm>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
#include <utility>
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

int check(vector<int> ans) {
    //return imbalance;
    vector<int> temp;
    int imbalance = *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() && ans.size() > 1; i += 2) {
        temp.push_back(ans[i] + ans[i + 1]);
        ans = temp;
        temp.clear();
        imbalance = max(imbalance, *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()));
    }
    return imbalance;
}
 
void solve()
{
    int N, k;
    cin >> N >> k;
    int n = 1 << N;
    vector<int> ans(n);
    int q = k / n, rem = k % n;
    fill(ans.begin(), ans.end(), q);
    queue<pair<int, int>> st;
    st.push({1, n});
    unordered_map<int, bool> vis;
    while (rem > 0) {
        auto [l, r] = st.front();
        st.pop();
        if (!vis[l]) {
            vis[l] = true;
            ans[l - 1]++;
            rem--;
        }
        if(!vis[r] && rem > 0) {
            vis[r] = true;
            ans[r - 1]++;
            rem--;
        }
        int sz = r - l + 1;
        if (l != r) {
            st.push({l, l + sz / 2 - 1});
            st.push({r - sz / 2 + 1, r});
        }
    }
    cout << check(ans) << "\n" << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}