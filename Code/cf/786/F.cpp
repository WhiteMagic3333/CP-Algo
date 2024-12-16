#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<numeric>
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

vector<ll> bit(1e6 + 2, 0);

ll sum (ll i)// sum till i
{
	ll ans = 0;
	while (i)
	{
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

void update(ll i, ll x) // add x to element at index i
{
	while (i <= 1e6)
	{
		bit[i] += x;
		i += (i & (-i));
	}
}


void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<char>> grid(n, vector<char> (m, '.'));
	
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	
	vector<ll> arr(n * m + 2);
	int k = 1;
	
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if(grid[i][j] == '*'){
				arr[k]++;
				update(k, arr[k]);
			}
			k++;
		}
	}
	while(q--)
	{
		ll a, b;
		cin >> a >> b;
		ll index = (b - 1) * n + a;
		a--, b--;
		if(grid[a][b] == '*')
		{
			grid[a][b] = '.';
			update(index, -1);
		}
		else
		{
			grid[a][b] = '*';
			update(index, 1);
		}
		ll total = sum(n * m);
		ll inside = sum(total);
		ll outside = total - inside;
		cout << outside << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}