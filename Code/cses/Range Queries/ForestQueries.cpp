#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007

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
	int n, q;
	cin >> n >> q;
	vector<vector<char>> arr(n + 1, vector<char> (n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	vector<vector<int>> rectangle_sum(n + 1, vector<int> (n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == '*')
				rectangle_sum[i][j] = 1;
			rectangle_sum[i][j] += rectangle_sum[i - 1][j] + rectangle_sum[i][j - 1] - rectangle_sum[i - 1][j - 1];
		}
	}
	while(q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int A = rectangle_sum[x2][y2];
		int B = rectangle_sum[x2][y1 - 1];
		int C = rectangle_sum[x1 - 1][y2];
		int D = rectangle_sum[x1 - 1][y1 - 1];
		int ans = A - B - C + D;
		cout << ans << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}