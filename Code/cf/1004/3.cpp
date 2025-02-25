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

int make_rest(vector<vector<int>> &mat, int v1, int v2) {
    int n = mat.size();
    //top_left_diag, top right diag,
    //lower mid col
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < (n / 2) && (i == j || (i + j) == (n - 1))) {
                cnt += (mat[i][j] != v1);
            } else if (i >= (n / 2) && j == n / 2) {
                cnt += (mat[i][j] != v1);
            } else {
                cnt += (mat[i][j] != v2);
            }
        }
    }
    return cnt;
}

int solution(vector<vector<int>> &mat) { //add &
    int n = mat.size();
    
    int ans = 1e9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                ans = min(ans, make_all(mat, i, j));
            }
        }
    }
    return ans;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int> (n));
    for (auto &row : mat) {
        cin >> row;
    }
    cout << solution(mat);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
    return 0;
}