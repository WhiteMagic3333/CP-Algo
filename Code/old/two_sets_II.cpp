#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
#include<set>
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
	int n;
	cin >> n;
	//int sum = (n * (n + 1)) / 2;
	//if (sum % 4)
	//	return void(cout << "0");

	multiset<int> m;
	m.insert(1);
	int i = 2;
	while(i <= n)
	{
		multiset<int> t;
		t.insert(i);
		for (auto p : m)
			t.insert(i + p);
		for (auto p : t)
			m.insert(p);
		t.erase(t.begin(), t.end());
		i++;
	}
	map<int, int> ma;
	for (auto p : m)
		ma[p]++;
	for (auto p : ma)
	cout << p.first << " " << p.second << "\n";

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}