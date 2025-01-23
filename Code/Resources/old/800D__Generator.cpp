#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<numeric>
#include<queue>
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
	srand(time(0));
	cout << "1\n";
	int n = rand() % 10 + 1;
	cout << n << "\n";
	vector<int> p(n + 1), order(n);
	queue<int> m;
	m.push(1);
	m.push(1);
	iota(order.begin(), order.end(), 1);
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	int shuffle = rand() % f;
	do {
		if (!shuffle)
			break;
		shuffle--;
	} while (next_permutation(order.begin(), order.end()));
	int s = order.size();
	cout << order;
	for (int i = 0; i < order.size(); i++)
	{
		if(order[i] == 1){
		cout << p[order[i]] << " ";
			continue;
		}
		p[order[i]] = m.front();
		m.push(order[i]);
		m.push(order[i]);
		m.pop();
		cout << p[order[i]] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}