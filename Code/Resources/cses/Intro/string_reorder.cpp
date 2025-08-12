#include <queue>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define INT_MIN 0
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
    string s;
    cin >> s;
    vector<int> f(26, 0);
    int max_freq = INT_MIN;

    // Count the frequency of each character
    for (char c : s) {
        f[c - 'A']++;
        max_freq = max(max_freq, f[c - 'A']);
    }

    // Check if a solution is possible
    if (max_freq > (s.length() + 1) / 2) {
        cout << -1 << endl;
        return;
    }

    // Create a list of valid characters
    vector<char> valid;
    for (int i = 0; i < 26; i++) {
        if (f[i] != 0) {
            valid.push_back(i + 'A');
        }
    }

    // Sort valid characters lexicographically
    sort(valid.begin(), valid.end());

    string result;
    while (result.length() != s.length()) {
        for (char c : valid) {
            if (f[c - 'A'] != 0 && (result.empty() || c != result[result.length() - 1])) {
                result += c;
                f[c - 'A']--;

                // Check if the max frequency exceeds the limit after adding the character
                int remPos = s.length() - result.length();
                int newMax = INT_MIN;
                for (int i = 0; i < 26; i++) {
                    newMax = max(newMax, f[i]);
                }

                if (newMax > (remPos + 1) / 2) {
                    result.pop_back();
                    f[c - 'A']++;
                } else {
                    break;
                }
            }
        }
    }

    cout << result << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}