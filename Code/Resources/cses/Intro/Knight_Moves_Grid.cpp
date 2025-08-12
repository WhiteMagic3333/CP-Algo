#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;

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

vector<array<int, 2>> dxy = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {-2, 1},
    {2, -1},
    {-2, -1}
};
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int> (n, -1));
    ans[0][0] = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (q.size()) {
        auto &[x, y, moves] = q.front();
        q.pop();
        for (auto d : dxy) {
            int dx = x + d[0], dy = y + d[1];
            if (dx >= 0 && dy >= 0 && dx < n && dy < n && ans[dx][dy] == -1) {
                ans[dx][dy] = moves + 1;
                q.push({dx, dy, moves + 1});
            }
        }
    }
    for (auto &row : ans) {
        cout << row;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}