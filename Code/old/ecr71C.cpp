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
	ll n, a, b;
	cin >> n >> a >> b;
	string str;
	cin >> str;
	vector<ll> pre_roads(n + 2, 0);
	vector<int> heights(n + 1, 1);
	for (int i = 0; i < n; i++)
		if(str[i] == '1')
			heights[i] = 2, heights[i + 1] = 2;
	int last_one = -1;
	for (int i = n; i >= 0; i--) {
		if (heights[i] == 1)
			pre_roads[i] = pre_roads[i + 1] + 1;
		else
			last_one = max(last_one, i);

	}
	int i = 1, h = 1, change = 0;
	vector<int> ans(n + 1, 1);
	while (i <= n)
	{
		if (i == last_one) {
			if (h == 1) {
				change += 2;
				h = 2;
			}
			else {
				change++;
				h = 1;
			}
			ans[i] = 2;
			h = 1;
			i++;
			continue;
		}
		if (heights[i] == 2) {
			if (h == 1)
				change++;
			h = 2;
		}
		else {
			if (h == 2) {
				if (((pre_roads[i] + 1) * (a + 2 * b)) <= ( 2 * a + (pre_roads[i] + 1) * a + (pre_roads[i] + 2) * b))
					h = 2;
				else {
					change++;
					h = 1;
				}
			}
			else
				h = 1;
		}
		ans[i] = h;
		i++;
	}
	ll final_ans = change * a + (a * n) + (b * (accumulate(ans.begin(), ans.end(), 0LL)));
	cout << final_ans;
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