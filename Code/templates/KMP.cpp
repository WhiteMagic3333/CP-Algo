#include<iostream>
#include<vector>
using namespace std;
 
void pre_computing(string &pat, vector<int> &pre)
{
	int n = pat.length();
	for (int i = 1; i < n; i++)
	{
		int j = pre[i - 1];
		while(j > 0 && pat[i] != pat[j])
			j = pre[j - 1];
		if(pat[i] == pat[j])
			j++;
		pre[i] = j;
	}
}
 
void kmp(string &txt, string &pat, int &ans)
{
	int n = txt.length(), m = pat.length();
	vector<int> pre(m, 0);
	/*
	pre[0] = 0;
	pre[i] -> max len of suffix till i which is also a prefix
	for eg
	aababaab
	01010123
	*/
	pre_computing(pat, pre);
	int i = 0, j = 0;
	while ((n - i) >= (m - j))
	{
		if (txt[i] == pat[j])
		{
			i++;
			j++;
			if (j == m)
			{
				ans++;
				j = pre[j - 1];
			}
		}
		else if (i < n)
		{
			if (j != 0)
				j = pre[j - 1];
			else
				i++;
		}
	}
}
 
void solve()
{
	string str;
	cin >> str;
 
	string pattern;
	cin >> pattern;
 
	int ans = 0;
 
	kmp(str, pattern, ans);
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}