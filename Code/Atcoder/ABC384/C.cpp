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
{f
        int n = nums.size();
        if (n == 0 || nums[0] > nums[1]) {
                return 0;
        } else if (nums[n - 1] > nums[n - 2]) {
                return n - 1;
        }
        int low = 1, high = n - 2;
        while(low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) {
                        ans = mid;
                        break;
                }else if (nums[mid - 1] < nums[mid]) {
                        low = mid + 1;
                } else {
                        high = mid - 1
                }
        }
}
 
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
 
        solve();
        return 0;
}