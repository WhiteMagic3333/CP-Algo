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

void solve()
{
	int n, root;
	cin >> n;
	vector<int> p(n);
	vector<bool> vis(n + 1, false);
	vector<int> parent(n + 1, -1);
	vector<vector<int>> child(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a == i) {
			root = a;
			continue;
		}
		child[a].push_back(i);
		parent[i] = a;
	}
	cin >> p;
	// for (int i = 1; i <= n; i++)
	// 	cout << parent[i] << "\n";
	for (int i = 0; i < n; i++) {
		if (p[i] != root && vis[parent[p[i]]] == false)
			return void(cout << "-1");
		vis[p[i]] = true;
	}
	vector<ll> ans(n + 1, 0);
	int prev = p[0];
	for (int i = 0; i < n; i++) {
		ans[p[i]] = i;
	};
	for (int i = n - 1; i > 0; i--) {
		if (p[i] == root)
			continue;
		ans[p[i]] = ans[p[i]] - ans[parent[p[i]]];
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
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