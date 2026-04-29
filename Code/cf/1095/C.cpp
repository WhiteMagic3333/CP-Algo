#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
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
 
bool check(int M, const vector<int>& arr) {
    vector<bool> vis(M, false);
    vector<int> extra;
    
    for (int x : arr) {
        if (x < M && !vis[x]) {
            vis[x] = true;
        } else {
            extra.push_back(x);
        }
    }
    
    int i = 0;
    for (int k = 0; k < M; k++) {
        if (!vis[k]) {
            while (i < extra.size() && extra[i] < 2 * k + 1) {
                i++;
            }
            if (i == extra.size()) {
                return false;
            }
            i++;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    sort(arr.begin(), arr.end());
    
    int low = 0, high = n;
    int mex = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, arr)) {
            mex = mid;     
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }
    
    cout << mex;
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