#include <algorithm>
#include <string>
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

vector<int> sail_time;

int n;

void dfs(int i, string &str) {
    if (i < 0 || i >= n || sail_time[i]) {
        return;
    }
    if (str[i] == '*' || str[i] == '<') {
        dfs(i - 1, str);
        sail_time[i] = max(sail_time[i], i == 0 ? 1 : 1 + sail_time[i - 1]);
    }
    if (str[i] == '*' || str[i] == '>') {
        dfs(i + 1, str);
        sail_time[i] = max(sail_time[i], i == n - 1 ? 1 : 1 + sail_time[i + 1]);
    }
}
 
void solve()
{   //18:47 took too long to solve this
    string str;
    cin >> str;
    //if i find **, >* or <* or ><  
    n = str.length();

    if (str.length() == 1) {
        cout << "1";
        return;
    }
    vector<string> loop = {"**", ">*", "*<", "><"};
    for (int i = 1; i < str.length(); i++) {
        for (string s : loop) {
            if (s[0] == str[i - 1] && s[1] == str[i]) {
                cout << "-1";
                return;
            }
        }
    }

    sail_time = vector<int> (n, 0);
    for (int i = 0; i < n; i++) {
        if (!sail_time[i]) {
            dfs(i, str);
        }
    }

    cout << *max_element(sail_time.begin(), sail_time.end());
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