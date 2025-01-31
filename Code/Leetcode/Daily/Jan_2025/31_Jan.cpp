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

int largestIsland(vector<vector<int>>& grid) {
    //get the area of all islands
    int n = grid.size();
    vector<long long> _area(1, 0); //1 based
    int islands = 1;
    vector<array<int, 2>> dxy = {
    	{0, 1},
    	{0, -1},
    	{1, 0},
    	{-1, 0},
    };
    //vis will store the island number for that land
    vector<vector<int>> vis(n, vector<int> (n, false));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (grid[i][j] && !vis[i][j]) {
    			queue<pair<int, int>> q;
    			q.push({i, j});
    			long long area = 1;
    			while(q.size()) {
    				auto [x, y] = q.front();
    				q.pop();
    				for (auto d : dxy) {
    					int dx = x + d[0], dy = y + d[1];
    					if (min(dx, dy) >= 0 && max(dx, dy) < n && grid[dx][dy] && !vis[dx][dy]) {
    						area++;
    						q.push({dx, dy});
    					}
    				}
    			}
    			_area.push_back(area);
    			islands++;
    			ans = max(ans, area);
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (!grid[i][j]) {
    			vector<int> _islands;
    			long long cur_area = 1;
    			for (auto d : dxy) {
					int dx = i + d[0], dy = j + d[1];
					if (min(dx, dy) >= 0 &&
						max(dx, dy) < n &&
						grid[dx][dy] &&
						find(_islands.begin(), _islands.end(), vis[dx][dy]) == _islands.end()
						) {
						_islands.push_back(vis[dx][dy]);
						cur_area += _area[_islands.back()];
					}
				}
				_islands.clear();
				ans = max(ans, cur_area);
    		}
    	}
    }
    return ans;
}
 
void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int> (n, 0));
	for (auto &row : grid) {
		for (auto &e : row) {
			cin >> e;
		}
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