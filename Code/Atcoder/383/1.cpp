#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	// #define int long long
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l, r;
	cin >> l >> r;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > l && arr[i] < r) {
			if (ans == -1) {
				ans = arr[i];
			} else {
				ans = min(ans, arr[i]);
			}
		} 
	}
	sort(arr.begin(), arr.end(), greater<int>());
	cout << ans;
	return 0;
}