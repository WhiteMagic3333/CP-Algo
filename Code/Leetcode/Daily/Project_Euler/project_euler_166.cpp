#include<bits/stdc++.h>
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
    int ans = 0;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                for (int d = 0; d < 10; d++) {
                    int s = a + b + c + d;
                    for (int e = 0; e < 10; e++) {
                        for (int f = 0; f < 10; f++) {
                            for (int g = 0; g < 10; g++) {
                                int h = s - e - f - g;
                                if (h < 0 || h > 9) {
                                    continue;
                                }
                                for (int i = 0; i < 10; i++) {
                                    int m = s - a - i - e;
                                    if (m < 0 || m > 9) {
                                        continue;
                                    }
                                    int j = s - (m + g + d);
                                    if (j < 0 || j > 9) {
                                        continue;
                                    }
                                    int n = s - b - f - j;
                                    if (n < 0 || n > 9) {
                                        continue;
                                    }
                                    for (int k = 0; k < 10; k++) {
                                        int l = s - i - j - k;
                                        int o = s - c - g - k;
                                        int p = s - d - h - l;
                                        if ((l < 0 || l > 9) || (o < 0 || o > 9) || (p < 0 || p > 9)) {
                                            continue;
                                        }
                                        int d1 = a + f + k + p;
                                        int d2 = d + g + j + m;
                                        if (d1 == d2 && d1 == s) {
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
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