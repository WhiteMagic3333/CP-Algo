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

string solution(string str) { //change name
    string a = "aeiou";
    string ans = "";
    for (char i : str) {
        bool valid = true;
        char ch = tolower(i);
        for (char j : a) {
            if (j == ch) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans += i;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
 
void solve()
{
    string str;
    cin >> str;
    cout << solution(str);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}