#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
	ll low = 1, high = 1e6, ans = 1e6;
	while (low <= high)
	{
		ll mid = low + (high - low) / 2;
		printf("%ld\n", mid);
		fflush(stdout);
		char s[3];
		scanf("%s", s);
		if (strcmp(s, "<") == 0)
			high = mid - 1;
		else{
			ans = mid;
			low = mid + 1;
		}
	}
	printf("! %ld\n", ans);
	fflush(stdout);
}

int main()
{
	solve();
	return 0;
}