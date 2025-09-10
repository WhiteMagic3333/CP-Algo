#include <iterator>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
#include <unordered_map>
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

unordered_map<char, array<long long, 2>> dxy;

vector<long long> move(vector<long long>&p, char &ch, long long times) {
    vector<long long> cur(2, 0);
    cur[0] = p[0] + dxy[ch][0] * times;
    cur[1] = p[1] + dxy[ch][1] * times;
    return cur;
}

long long distance(vector<ll> a, vector<ll> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
 
void solve()
{
    dxy['L'] = {0, -1};
    dxy['R'] = {0, 1};
    dxy['U'] = {-1, 0};
    dxy['D'] = {1, 0};
    vector<long long> p(2), q(2);
    cin >> p >> q;
    ll n;
    cin >> n;
    long long l1, l2;
    cin >> l1 >> l2;
    queue<pair<char, int>> s, t;
    for (int i = 0; i < l1; i++) {
        pair<char, int> cur;
        cin >> cur.first >> cur.second;
        s.push(cur);
    }
    for (int i = 0; i < l2; i++) {
        pair<char, int> cur;
        cin >> cur.first >> cur.second;
        t.push(cur);
    }
    long long ans = 0;
    int cnt = 0;
    while (s.size() && t.size()) {
        auto &[d1, times1] = s.front(); //dir, times 
        auto &[d2, times2] = t.front();
        long long dis = distance(p, q);
        long long times = min(times1, times2);
        if (p == q) { //at same points
            if (d1 == d2) {
                ans += times;   
            }
            p = move(p, d1, times);
            q = move(q, d2, times);
            times1 -= times;
            times2 -= times;
        } else {
            if (d1 == d2) { //same direction but different points so cant meet
                p = move(p, d1, times);
                q = move(q, d2, times);
                times1 -= times;
                times2 -= times;
            } else {
                if (dis < distance(move(p, d1, 1), move(q, d2, 1))) {
                    //going away
                    p = move(p, d1, times);
                    q = move(q, d2, times);
                    times1 -= times;
                    times2 -= times;
                } else { //getting closer
                    long long low = 1, high = times;
                    while (low <= high) { //last values
                        long long mid = low + (high - low) / 2LL;
                        if (distance(move(p, d1, mid - 1), move(q, d2, mid - 1)) >= distance(move(p, d1, mid), move(q, d2, mid))) {
                            //getting closer
                            times = mid;
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                    p = move(p, d1, times);
                    q = move(q, d2, times);
                    times1 -= times;
                    times2 -= times;
                    if (p == q) {
                        ans++;
                    }
                }
            }
        }
        if (times1 == 0) {
            s.pop();
        }
        if (times2 == 0) {
            t.pop();
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