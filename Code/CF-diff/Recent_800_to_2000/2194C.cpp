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
{   //16 mins
    //n . k is upto 1e5
    //let n = 500 and k = 100
    //for each letter know the idx
    //check for all the factors of k
    int n, k;
    cin >> n >> k;
    vector<string> arr(k);
    for (auto &s : arr) {
        cin >> s;
    }
    vector<int> fac;
    vector<vector<bool>> pres(n, vector<bool> (26, false));
    for (auto s : arr) {
        for (int i = 0; i < n; i++) {
            pres[i][s[i] - 'a'] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            fac.push_back(i);
        }
    }
    for (auto len : fac) {
        int valids = 0;
        string cur(n, 'a');
        for (int i = 0; i < len; i++) {
            bool valid = false;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                int x = ch - 'a', j = i;
                while (j < n && pres[j][x]) {
                    cur[j] = ch;
                    j += len;
                }
                if (j >= n) {
                    valid = true;
                    break;
                }
            }
            if (valid) {
                valids++;
            }
        }
        if (valids == len) {
            cout << cur;
            break;
        }
    }
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