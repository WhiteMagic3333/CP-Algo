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

bool valid(int k, vector<int> &index, vector<char> & arr, vector<int> &ones, int n)
{
	if (k >= index.size())
		return true;
	for (int i = k - 1; i < index.size(); i++)
	{
		int ones_inside = ones[n - 1];
		if((i - k + 1) != 0)
			ones_inside -= ones[index[i - k]];
		if(i != index.size() - 1)
			ones_inside -= (ones[n - 1] - ones[index[i + 1]]);
		int ones_outside = ones[n - 1] - ones_inside;
		if (ones_outside <= k)
			return true;
	}
	return false;
}


void solve()
{
	string str;
	cin >> str;
	vector<char> arr;
	int j = 0, last_one = str.length() - 1;
	while (j < str.length() && str[j] == '0')
		j++;
	while (last_one >= 0 && str[last_one] == '0')
		last_one--;
	while ( j <= last_one)
		arr.push_back(str[j++]);

	int n = arr.size();
	vector<int> zeroes, ones(n);
	for (int i = 0; i < n; i++) {
		if (arr[i] == '0')
			zeroes.push_back(i);
		else
			ones[i]++;
		if (i != 0)
			ones[i] += ones[i - 1];
	}
	int low = 0, high = n, ans = n;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if ( valid(mid, zeroes, arr, ones, n))
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << ans;

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
