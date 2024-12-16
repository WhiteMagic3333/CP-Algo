#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b)        for(int i=a;i<b;i++)
#define int             long long
#define modm            1000000007
#define vi              vector<int>
#define pb              push_back

int n, m;
int dp[1005][(1 << 12)];

//generating all possible mask- representing all possible states given the current mask
//here i represents the row
void generate_next_masks(int current_mask, int i, int next_mask, vi& container) {

	if (i == (n + 1)) {
		container.pb(next_mask);
		return;
	}
	if (current_mask & (1 << i)) {
		generate_next_masks(current_mask, i + 1, next_mask, container);
	}
	if (i != n) {

		if (((current_mask & (1 << i)) == 0) and ((current_mask & (1 << (i + 1))) == 0)  ) {
			generate_next_masks(current_mask, i + 2, next_mask, container);
		}
	}

	if ((current_mask & (1 << i)) == 0) {
		generate_next_masks(current_mask, i + 1 , next_mask + (1 << i) , container);
	}
}

int solve(int col, int mask) {

	if (col == (m + 1)) {
		//checking that no block flows out of the board at the last column. That's there is not block of size 1x2 in the ith column
		if (mask == 0) {
			return (1);
		}
		return (0);
	}

	if (dp[col][mask] != -1) {return (dp[col][mask]);}
	int ans = 0;
	vi next_masks;
	generate_next_masks(mask, 1, 0, next_masks);

	//trying with all possible mask for the current column
	for (auto maskk : next_masks) {
		ans = (ans % modm + solve(col + 1, maskk) % modm) % modm;
	}
	next_masks.clear();
	return (dp[col][mask] = ans % modm);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0) << "\n";
	return 0;
}