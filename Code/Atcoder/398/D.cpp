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
        std::cout << x;
    std::cout << '\n';
    return out;
}

void move(char &ch, ll &i, ll &j) {
    if (ch == 'N') {
        i++;
    } else if (ch == 'S') {
        i--;
    } else if (ch == 'E') {
        j--;
    } else {
        j++;
    }
}
 
void solve()
{
    ll n, r, c;
    string str;
    cin >> n >> r >> c >> str;
    map<pair<int, int>, int> m;
    m[{0, 0}] = true;
    ll ci = 0, cj = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        move(str[i], ci, cj);
        move(str[i], r, c);
        m[{ci, cj}] = true;
        ans.push_back(m[{r, c}]);
    }
    cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}