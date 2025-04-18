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

int consec(string &str) {
    int cur = 1, mx = 0;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        mx = max(cur, mx);
    }
    return mx;
}

bool valid(string &str, int n, int k) {
    if (consec(str) < k) {
        return true;
    }
    int cur = 1, idx = -1, rev_idx = n;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i - 1]) {
            cur++;
            if (cur == k) {
                idx = i;
                break;
            }
        } else {
            cur = 1;
        }
    }
    cur = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (str[i] == str[i + 1]) {
            cur++;
            if (cur == k) {
                rev_idx = i;
                break;
            }
        } else {
            cur = 1;
        }
    }
    if (idx == rev_idx) {
        return false;
    }
    if (idx > rev_idx) {
        cur = 1;
        if (idx != n - 1 && str[n - 1] != str[idx]) {
            rev_idx = n - 1;
        } else {
            //this is wrong
            int mx = 1e9, after = n;
            for (int i = idx + 1; i < n; i++) {
                if (str[i] != str[idx]) {
                    after = i;
                    break;
                }
            }
            for (int i = n - 2; i >= after; i--) {
                if (str[i] != str[idx]) {
                    if (str[i] == str[i + 1]) {
                        rev_idx = i;
                        break;
                    } else if (cur < mx) {
                        mx = cur;
                        rev_idx = i;
                    }
                }
                if (str[i] == str[i + 1]) {
                    cur++;
                } else {
                    cur = 1;
                }
            }
        }
    }
    if (idx > rev_idx) {
        return false;
    }
    string ans = "";
    for (int i = 0; i < idx; i++) {
        ans += str[i];
    }
    for (int i = rev_idx; i >= idx; i--) {
        ans += str[i];
    }
    for (int i = rev_idx + 1; i < n; i++) {
        ans += str[i];
    }
    if (consec(ans) < k) {
        return true;
    }
    return false;
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    string cpy = str;
    reverse(str.begin(), str.end());
    if (valid(cpy, n, k) || valid(str, n, k)) {
        cout << "Yes";
    } else {
        cout << "No";
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