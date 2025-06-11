// 2106E
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    vector<int> idx_of(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        idx_of[arr[i]] = i;
    }
    vector<vector<int>> queries;
    vector<int> ans;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int cur_ans = 0;
        int idx = idx_of[k];
        if (idx < l || idx > r) {
            ans.push_back(-1);
        } else {
            int low = l, high = r;
            int ahead = 0, behind = 0;
            int smaller_ahead = 0, greater_behind = 0;
            while (1) {
                int mid = low + (high - low) / 2;
                // cout << mid << " " << arr[mid] << "\n";
                if (mid > idx) {
                    ahead++;
                    if (arr[mid] < k) {
                        smaller_ahead++;
                    }
                    high = mid - 1;
                } else if (mid < idx) {
                    behind++;
                    if (arr[mid] > k) {
                        greater_behind++;
                    }
                    low = mid + 1;
                } else if (mid == idx) {
                    break;
                }
            }

            // cout << smaller_ahead <<" " << greater_behind << " -\n";

            int greater_ahead = ahead - smaller_ahead;
            int big_available = n - k - greater_ahead;
            int smaller_behind = behind - greater_behind;
            int smaller_available = (k - 1) - smaller_behind;

            if (smaller_ahead == greater_behind) {
                ans.push_back(smaller_ahead * 2);
            } else if (smaller_ahead > greater_behind) {
                cur_ans += greater_behind * 2;
                smaller_ahead -= greater_behind;
                big_available -= greater_behind;
                if (smaller_ahead > big_available) {
                    ans.push_back(-1);
                    continue;
                }
                cur_ans += smaller_ahead * 2;
                ans.push_back(cur_ans);
            } else {
                cur_ans += smaller_ahead * 2;
                greater_behind -= smaller_ahead;
                smaller_available -= smaller_ahead;
                if (greater_behind > smaller_available) {
                    ans.push_back(-1);
                    continue;
                }
                cur_ans += greater_behind * 2;
                ans.push_back(cur_ans);
            }
        }
    }
    // cout << arr;

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