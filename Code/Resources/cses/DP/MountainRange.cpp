#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
using namespace std;
#define ll long long
 
vector<ll> bin_log(2e5 + 1, 0LL);
vector<vector<array<ll, 2>>> table;
 
array<ll, 2> get_max_with_idx(array<ll, 2> &a, array<ll, 2> &b) {
    if (a[0] == b[0]) {
        return a[1] < b[1] ? a : b;
    } else if (a[0] > b[0]) {
        return a;
    }
    return b;
}
 
array<ll, 2> query(ll L, ll R)
{
    int len = R - L + 1;
    ll i = bin_log[len];
    return get_max_with_idx(table[i][L], table[i][R - (1LL << i) + 1]);
}
 
int rec(int l, int r, int prev) {
    if (l > r) {
        return 0;
    } else if (l == r) {
        return prev != query(l, r)[0];
    }
    array<ll, 2> mx = query(l, r);
    int add = (prev != mx[0]);
    return add + max(rec(l, mx[1] - 1, mx[0]), rec(mx[1] + 1, r, mx[0]));
}
 
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (ll i = 2; i <= 2e5; i++)
        bin_log[i] = bin_log[i/2] + 1;
    //max
    table = vector<vector<array<ll, 2>>> (33, vector<array<ll, 2>> (n));
    for (int i = 0; i < n; i++) {
        table[0][i] = {arr[i], i};
    }
    for (ll i = 1; i < 32; i++) {
        for (ll j = 0; (j + (1LL << (i)) - 1) < n; j++) {
            table[i][j] = get_max_with_idx(table[i - 1][j], table[i - 1][j + (1LL << (i - 1))]);
        }
    }
    cout << rec(0, n - 1, 1e9 + 1);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}