#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<stack>
#include<math.h>
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

int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}

int apply(int a, int b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	}
	return 0;
}

int calculate(string pre) {//rename str as pre
	
	vector<char> str;
	for (int i = 0; i < pre.length(); i++)
	{
		if (pre[i] == '*' && str.size() && str.back() == '*')
		{
			str.pop_back();
			str.push_back('^');
		}
		else if (pre[i] != ' ')
			str.push_back(pre[i]);
	}
	int n = str.size();
	stack<int> values;
	stack<char> op;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			op.push(str[i]);
		else if (isdigit(str[i]))
		{
			int cur = 0;
			while (i < n && isdigit(str[i]))
			{
				cur = cur * 10 + (str[i] - '0');
				i++;
			}
			i--;
			values.push(cur);
		}
		else if (str[i] == ')')
		{
			while (op.size() && op.top() != '(')
			{
				int b = values.top();
				values.pop();

				int a = values.top();
				values.pop();

				int cur = apply(a, b, op.top());
				op.pop();

				values.push(cur);
			}

			if (op.size())
				op.pop();
		}
		else
		{
			while (op.size() && precedence(op.top()) >= precedence(str[i]))
			{
				//copy line 97 to 106
				int b = values.top();
				values.pop();

				int a = values.top();
				values.pop();

				int cur = apply(a, b, op.top());
				op.pop();

				values.push(cur);
			}
			op.push(str[i]);
		}
	}

	while (op.size())
	{
		//copy line 97 to 106
		int b = values.top();
		values.pop();

		int a = values.top();
		values.pop();

		int cur = apply(a, b, op.top());
		op.pop();

		values.push(cur);
	}
	return values.top();
}

void solve()
{
	string str;
	cin >> str;
	cout << calculate(str);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}