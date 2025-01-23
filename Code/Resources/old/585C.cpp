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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int s_a = count(s.begin(), s.end(), 'a'), t_a = count(t.begin(), t.end(), 'a');
	if((s_a + t_a) % 2)
		return void(cout << "-1");
	vector<int> ab, ba;
	vector<array<int, 2>> ans;
	for (int i = 0; i < n; i++)
	{
		if(s[i] != t[i])
		{
			if(s[i] == 'a')
				ab.push_back(i);
			else
				ba.push_back(i);
		}
	}
	while(ab.size() > 1)
	{
		ans.push_back({ab[ab.size() - 2], ab[ab.size() - 1]});
		ab.pop_back();
		ab.pop_back();
	}
	while(ba.size() > 1)
	{
		ans.push_back({ba[ba.size() -2], ba[ba.size() - 1]});
		ba.pop_back();
		ba.pop_back();
	}
	if((ab.size()))
	{
		ans.push_back({ab[0], ab[0]});
		ans.push_back({ab[0], ba[0]});
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i][0]  + 1 <<  " " << ans[i][1] + 1 << "\n";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}