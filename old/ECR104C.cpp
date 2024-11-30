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
	vector<array<int, 3>> arr(n + 1);
	int tie = (n - 1) % 2;
	for (int i = 1; i <= n; i++)
		arr[i] = {tie, (n - 1) / 2, (n - 1) / 2};
	for(int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if(arr[i][0] && arr[j][0])
			{
				cout << "0 ";
				arr[i][0]--;
				arr[j][0]--;
			}
			else if(arr[i][1] && arr[j][2])
			{
				cout << "1 ";
				arr[i][1]--;
				arr[j][2]--;
			}
			else
			{
				cout << "-1 ";
				arr[i][2]--;
				arr[j][1]--;
			}
		}
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