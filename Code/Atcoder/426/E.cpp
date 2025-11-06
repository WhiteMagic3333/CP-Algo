#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double EPS = 1e-7;

// Position at time t moving from s to g at speed 1
vector<long double> fun(const vector<ll>& s, const vector<ll>& g, long double t) {
    long double dx = g[0] - s[0];
    long double dy = g[1] - s[1];
    long double dist = sqrt(dx * dx + dy * dy);
    if (dist < EPS || t >= dist) {
        return { (long double)g[0], (long double)g[1] };
    }
    long double ratio = t / dist;
    return { s[0] + dx * ratio, s[1] + dy * ratio };
}

// Squared distance between two points
long double dist2(const vector<long double>& a, const vector<long double>& b) {
    long double dx = a[0] - b[0];
    long double dy = a[1] - b[1];
    return dx * dx + dy * dy;
}

// Binary search to find minimum distance
void solve() {
    vector<ll> s1(2), g1(2), s2(2), g2(2);
    cin >> s1[0] >> s1[1] >> g1[0] >> g1[1];
    cin >> s2[0] >> s2[1] >> g2[0] >> g2[1];

    // Time bounds
    long double d1 = sqrt((g1[0] - s1[0]) * (g1[0] - s1[0]) + (g1[1] - s1[1]) * (g1[1] - s1[1]));
    long double d2 = sqrt((g2[0] - s2[0]) * (g2[0] - s2[0]) + (g2[1] - s2[1]) * (g2[1] - s2[1]));
    long double low = 0.0, high = max(d1, d2);

    while (high - low > EPS) {
        long double mid1 = low + (high - low) / 2.0;
        long double mid2 = mid1 + EPS;

        vector<long double> pos1_m1 = fun(s1, g1, mid1);
        vector<long double> pos2_m1 = fun(s2, g2, mid1);
        long double d_m1 = dist2(pos1_m1, pos2_m1);

        vector<long double> pos1_m2 = fun(s1, g1, mid2);
        vector<long double> pos2_m2 = fun(s2, g2, mid2);
        long double d_m2 = dist2(pos1_m2, pos2_m2);

        if (d_m1 < d_m2) {
            high = mid2;
        } else {
            low = mid1;
        }
    }

    long double final_time = (low + high) / 2.0;
    vector<long double> pos1 = fun(s1, g1, final_time);
    vector<long double> pos2 = fun(s2, g2, final_time);
    long double final_dist = sqrt(dist2(pos1, pos2));

    cout << fixed << setprecision(12) << final_dist << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
