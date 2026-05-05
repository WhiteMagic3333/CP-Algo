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

char get_first(vector<int> &f) {
    for (int i = 0; i < 26; i++) {
        if (f[i]) {
            return 'a' + i;
        }
    }
    return 'z';
}
 
void solve()
{   //still blurry
    string s, t;
    cin >> s >> t;
    vector<int> f(26, 0);
    for (auto i : t) {
        f[i - 'a']++;
    }
    for (auto i : s) {
        f[i - 'a']--;
        if (f[i - 'a'] < 0) {
            cout << "Impossible";
            return;
        }
    }
    string ans = "";
    int j = 0;
    while (ans.size() < t.size()) {
        char tch = get_first(f);
        char sch = (j == s.length()) ? 'z' + 1 : s[j];
        if (tch < sch) {
            ans += tch;
            f[tch - 'a']--;
        } else {
            ans += sch;
            j++;
        }
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