#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<map>
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
	int n;
	cin >> n;
	vector<vector<int>> arr(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	if(arr[1].size()== 0)
		return void(cout << n - 1);
	else if(arr[1].size() == 1)
		return void(cout << n - 2);
	int ans = n;
	vector<bool> vis(n + 1, false);
	vis[1] = true;
	queue<pair<int, int>> q;// distance, element
	for(int i = 0; i < arr[1].size(); i++){
		vis[arr[1][i]] = true;
		q.push({1, arr[1][i]});
	}
	while(q.size())
	{
		int dis = q.front().first;
		if(dis * 2 > ans)
			break;
		int ele = q.front().second;
		q.pop();
		if(arr[ele].size() == 2)
			ans = min(ans, dis * 2 + 1);
		if(arr[ele].size() == 1)
			ans = min(ans, dis * 2);
		for (int i = 0; i < arr[ele].size(); i++){
			if(!vis[arr[ele][i]]) {
				vis[arr[ele][i]] = true;
				q.push({dis + 1, arr[ele][i]});
			}
		}
	}
	while(q.size())
		q.pop();
	cout << n - ans - 1;
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