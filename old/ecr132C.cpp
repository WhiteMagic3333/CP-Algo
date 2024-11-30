#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<stack>
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
	string str;
	cin >> str;
	stack<int> s;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] != ')')
			s.push(1);
		else
			s.pop();
	}
	int ans = int(s.size());
	while(s.size())
		s.pop();
	for(int i = str.length() - 1; i >= 0; i--)
	{
		if(str[i] != '(')
			s.push(1);
		else
			s.pop();
	}
	ans = min(ans, int(s.size()));
	if(ans == 0)
		cout << "YES";
	else if(ans > 2)
		cout << "NO";
	else if(ans == 2)
	{
		cout << "NO idea";
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
		cout << "\n";
	}
	return 0;
}