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

vector<int> solution(vector<int> a, vector<int> b, vector<vector<int>> queries) {
	unordered_map<int, int> m;
	for (auto i : a) {
		m[i]++;
	}

	vector<int> res;

	for (auto &q : queries) {
		if (q[0] == 0) {
			int i = q[1];
			m[a[i]]--;
			a[i] = q[2];
			m[q[2]]++;
		} else {
			int x = q[1];
			int ans = 0;
			for (auto &cur : b) {
				int rem = x - cur;
				//removed if
				ans += m[rem];
			}
			res.push_back(ans);
		}
	}
	return res;
}
 
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	cin >> a >> b;
	int c;
	cin >> c;
	vector<vector<int>> q(c);
	for (int i = 0; i < c; i++)
	{
		int t;
		cin >> t;
		if (t == 0) {
			int in, e;
			cin >> in >> e;
			q.push_back({t, in, e});
		} else {
			int x;
			cin >> x;
			q.push_back({t, x});
		}
	}
	vector<int> res = solution(a, b, q);
	cout << res;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}