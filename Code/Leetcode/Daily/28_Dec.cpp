#include<bits/stdc++.h>
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

void print(vector<pair<long long, int>> cur) {
	cout << '\n';
	for (auto c : cur) {
		cout << c.first << " ";
	}
	cout << '\n';
	for (auto c : cur) {
		cout << c.second << " ";
	}
	cout << '\n';
}

vector<int> maxSumOfThreeSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<pair<long long, int>> suf(n), pre(n);
    vector<long long> sum(n + 1, 0);
    //ending index for prefix 
    long long cur_sum = 0;
    for (int i = 0; i < k; i++) {
        cur_sum += arr[i];
    }
    // max_sub array ending at k - 1
    pre[k - 1] = {cur_sum, 0};
    sum[0] = cur_sum;
    for (int i = k; i < n; i++) {
        cur_sum += arr[i];
        cur_sum -= arr[i - k];
        sum[i - k + 1] = cur_sum;
        pre[i] = pre[i - 1];
        if (pre[i].first <= cur_sum) {
            //pre[ending_index] sum, startingIdx
            pre[i] = {cur_sum, i - k + 1};
        }
    }
    cur_sum = 0;
    for (int i = n - 1; i > n - 1 - k; i--) {
        cur_sum += arr[i];
    }
    suf[n - k] = {cur_sum, n - k};
    for (int i = n - 1 - k; i >= 0; i--) {
        cur_sum += arr[i];
        cur_sum -= arr[i + k];
        suf[i] = suf[i + 1];
        if (suf[i].first < cur_sum) {
            suf[i] = {cur_sum, i};
        }
    }
    int ans = 0;
    vector<int> answer;
    for (int i = k; i < n - k; i++) {
        long long cur_sum = sum[i] + pre[i - 1].first + suf[i + k].first;
        if (cur_sum > ans) {
            ans = cur_sum;
            answer = {pre[i - 1].second, i, suf[i + k].second};
        }
    }
    // cout << ans << '\n';
    return answer;
}
 
void solve()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> arr(n);
	cin >> arr;
	vector<int> ans = maxSumOfThreeSubarrays(arr, k);
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}