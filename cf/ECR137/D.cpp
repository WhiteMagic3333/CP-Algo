#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
//just checkin
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
		std::cout << x ;
	std::cout << '\n';
	return out;
}

void solve()
{
	int n;
	cin >> n;
	vector<char> str;
	char ch;
	while (n--)
	{
		cin >> ch;
		if (ch == '1') {
			str.push_back(ch);
			break;
		}
	}
	n = max(0, n);
	while (n--)
	{
		cin >> ch;
		str.push_back(ch);
	}
	n = str.size();
	int cnt = count(str.begin(), str.end(), '0');
	if (n == 0)
		return void(cout << n);
	else if (cnt == 0)
		return void(cout << str);
	int block = 0;
	cnt = 0;
	vector<int> moves;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '1') {
			cnt++;
			moves.push_back(cnt);
		}
		else
			break;
	}
	vector<char> ans = str;
	// sure
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0')
		{
			vector<int> rem;
			for (int j = 0; j < moves.size(); j++)
			{
				if (str[i - moves[j]] == '0')
					rem.push_back(moves[j]);
			}
			for (int j = 0; j < rem.size(); j++)
			{
				auto p = find(moves.begin(), moves.end(), rem[j]);
				moves.erase(p);
			}
			if(moves.size())
				ans[i] = '1';
			else
				moves = rem;
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}