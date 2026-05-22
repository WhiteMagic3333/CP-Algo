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

string mul(string prev, char ch) {
    string cur = "";
    int carry = 0;
    for (int i = prev.length() - 1; i >= 0; i--) {
        int res = (prev[i] - '0') * (ch - '0') + carry;
        carry = res / 10;
        int d = res % 10;
        cur += to_string(d);
    }
    if (carry) {
        cur += to_string(carry);
    }
    reverse(cur.begin(), cur.end());
    return cur;
}

string add(string prev, char digit) {
    int d = digit - '0';
    string cur = "";
    int carry = 0;
    for (int i = prev.length() - 1; i >= 0; i--) {
        int res = (prev[i] - '0') + digit + carry;
        carry = res / 10;
        int d = res % 10;
        digit = 0;
        cur += to_string(d);
    }
    if (carry) {
        cur += to_string(carry);
    }
    reverse(cur.begin(), cur.end());
    return cur;
}
 
void solve()
{
    // 71 * 33 = (70 + 1) * (30 + 3) = 70 * 30 + 70 * 3
    //nice idea couldnt think on my own but ok
    //if sum of both numbers is s
    //then s/2 ans s/2 are two halfs or two numbers that form sum s
    //now our given two numbers would be (s/2 - a) ans (s/2 + a),
    //equidistant for half so multiplying both
    // (s/2 - a) . (s/2 + a)
    // (s/2)^2 - (a) ^ 2, the more the diff the smaller the product
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a << "\n" << b;
        return;
    }
    //find msb unequal, all bits are higher in smaller number
    if (a < b) {
        swap(a, b);
    }
    bool first = true;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] > b[i]) {
            if (first) {
                first = false;
                continue;
            }
            swap(a[i], b[i]);
        }
    }
    cout << a << "\n" << b;
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