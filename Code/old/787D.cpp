#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
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

vector<int> dfs(int e, vector<vector<int>> &c, vector<vector<int>> &ans)
{
	vector<vector<int>> a;
	vector<int> send;

	if (c[e].size()) {
		int index = -1, mx = 0;
		for (int i = 0; i < c[e].size(); i++)
		{
			a.push_back(dfs(c[e][i], c, ans));
			if(a[i].size() > mx) {
				mx = a[i].size();
				index = i; 
			}
		}
		swap(send, a[index]);
		for (int i = 0; i < a.size(); i++)
		{
			if(i != index)
				ans.push_back(a[i]);
		}
	}
	a.clear();
	send.push_back(e);
	return send;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> c(n + 1);
	int root = -1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (i == x) {
			root = i;
			continue;
		}
		c[x].push_back(i);
	}
	vector<vector<int>> ans;
	ans.push_back(dfs(root, c, ans));
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].size() << "\n";
		for (int j = ans[i].size() - 1; j >= 0; j--)
		{
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

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
		cout << '\n';
	}
	return 0;
}