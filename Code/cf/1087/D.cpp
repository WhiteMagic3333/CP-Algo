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
 
void solve() {
    vector<int> counts(3);
    cin >> counts[0] >> counts[1] >> counts[2];
    
    char chars[3] = {'R', 'G', 'B'};
    string s = "";
    
    s.reserve(counts[0] + counts[1] + counts[2]); 

    while (true) {
        int best_c = -1;
        int max_count = -1;

        for (int c = 0; c < 3; c++) {
            if (counts[c] == 0) continue;

            int len = s.length();
            
            if (len >= 1 && s[len - 1] == chars[c]) continue;
            
            if (len >= 3 && s[len - 3] == chars[c]) continue;

            bool is_prev2 = (len >= 2 && s[len - 2] == chars[c]);

            if (best_c == -1) {
                best_c = c;
                max_count = counts[c];
            } else {
                if (counts[c] > max_count) {
                    best_c = c;
                    max_count = counts[c];
                } else if (counts[c] == max_count) {
                    bool best_is_prev2 = (len >= 2 && s[len - 2] == chars[best_c]);
                    if (is_prev2 && !best_is_prev2) {
                        best_c = c;
                        max_count = counts[c];
                    }
                }
            }
        }

        if (best_c == -1) break;

        s += chars[best_c];
        counts[best_c]--;
    }
    
    cout << s;
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