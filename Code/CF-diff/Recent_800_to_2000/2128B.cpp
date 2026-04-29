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
    //12:28 avg but i wasnt confident
    //small large large small
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    string ans = "";
    int i = 0, j = n - 1;
    int turn = 0;
    while (i < j) {
        int small = arr[i], large = arr[j];
        int x = i, y = j;
        if (small > large) {
            swap(x, y);
        }
        if (turn) { //small large
            if (i == x) {
                ans.append("LR");
            } else {
                ans.append("RL");
            }
        } else {
            if (i == x) {
                ans.append("RL");
            } else {
                ans.append("LR");
            }
        }
        turn ^= 1;
        i++;
        j--;
    }
    if (i == j) {
        ans.push_back('L');
    }
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
        cout << "\n";
    }
    return 0;
}