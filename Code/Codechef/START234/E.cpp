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
 
struct Fenwick {
    int n; vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int i, int val) { 
        for (++i; i <= n; i += i & -i) tree[i] += val; 
    }
    
    int query(int i) { 
        int sum = 0; 
        for (++i; i > 0; i -= i & -i) sum += tree[i]; 
        return sum; 
    }
    
    int query(int l, int r) { 
        return l > r ? 0 : query(r) - query(l - 1); 
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    cin >> A >> B;

    long long total = 0;

    for (int p = 0; p < 2; ++p) {
        vector<int> a, b;
        for (int x : A) if (x % 2 == p) a.push_back(x / 2);
        for (int x : B) if (x % 2 == p) b.push_back(x / 2);
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        for (int k = 0; k < 20; ++k) {
            int M = 1 << (k + 1);
            int H = 1 << k;
            
            Fenwick fenw(M);
            int ptr = 0;
            
            for (int y : b) {
                while (ptr < a.size() && a[ptr] >= y) {
                    fenw.add(a[ptr] % M, 1);
                    ptr++;
                }
                
                int original_B = 2 * y + p;
                int bit_B = (original_B >> k) & 1;
                
                int rem_y = y % M;
                int L, R;
                
                if (bit_B == 0) {
                    L = rem_y + H;
                    R = rem_y + M - 1;
                } else {
                    L = rem_y;
                    R = rem_y + H - 1;
                }
                
                if (L >= M) {
                    L -= M;
                    R -= M;
                }
                
                if (R >= M) {
                    total += fenw.query(L, M - 1) + fenw.query(0, R - M);
                } else {
                    total += fenw.query(L, R);
                }
                total %= 998244352; 
            }
        }
    }

    long long ans = 1, base = 3, exp = total;
    while (exp > 0) {
        if (exp % 2 == 1) ans = (ans * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    cout << ans << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}