/*
In a binary tree it is possible that left sub tree is longer than the right
subtree so using bfs the order is not as expected
level wise bfs could work but then why take so much of trouble use dfs instead
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<queue>
#include<numeric>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define rlp(i,a,b) for (int i = b; i >= b; i--)
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

ll dfs(int i, vector<vector<int>> &graph, vector<array<ll, 2>> &range, int &ans)
{
	ll mx = 0;
	for (int j = 0; j < graph[i].size(); j++)
		mx += dfs(graph[i][j], graph, range, ans);
	if (mx < range[i][0]) {
		ans++;
		return range[i][1];
	}
	return min(mx, range[i][1]);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> p(n + 1, 0);
	vector<vector<int>> children(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		children[p[i]].push_back(i);
	}
	vector<array<ll, 2>> range(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> range[i][0] >> range[i][1];
	int ans = 0;
	dfs(1, children, range, ans);
	cout << ans;

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