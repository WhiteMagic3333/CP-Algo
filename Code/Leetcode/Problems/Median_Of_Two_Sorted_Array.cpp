#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
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

int m, n;

int check(int a_mid, vector<int> &a, vector<int> &b, int &a_low, int &a_high, int i) {
	if (a_high < a_low) {
		return false;
	}
	int index = a_mid;

	int lower_house = (int)(lower_bound(b.begin(), b.end(), a[a_mid]) - b.begin());
	int upper_house = (int)(upper_bound(b.begin(), b.end(), a[a_mid]) - b.begin());
	int diff = upper_house - lower_house;
	index += (int)(upper_bound(b.begin(), b.end(), a[a_mid] - 1) - b.begin());



	if (diff == 0) {
		if (index == i) {
			return true;
		} else if (index < i) {
			a_low = a_mid + 1;
		} else {
			a_high = a_mid - 1;
		}
	} else {
		if (index <= i && (index + diff) >= i) {
			return true;
		} else if (index + diff < i) {
			a_low = a_mid + 1;
		} else {
			a_high = a_mid - 1;
		}
	}
	return false;
}

//how many elements are smaller than this
		//in the combined array

		//log(a) * Log(b) = log(a + b)

		//update a_low, b_low
		//i = 5
		//A = [2, 3, 5, 70, 80, 90, 120]
		//B = [4, 14, 15, 100]
		//AB =[2, 3, 4, 5, 14, 15, 70, 80, 90, 100, 120]
		//a_mid = 3 [70]
		//a_mid_index = 6
		//a_high = 2
		//b_mid = 1 [14]
		//b_

int nth(vector<int> &a, vector<int> &b, int i) {
	int a_low = 0, b_low = 0, a_high = m - 1, b_high = n - 1;
	while(1) {
		int a_mid = a_low + (a_high - a_low) / 2;
		int b_mid = b_low + (b_high - b_low) / 2;
		if(check(a_mid, a, b, a_low, a_high, i)) {
			return a[a_mid];
		}
		if (check(b_mid, b, a, b_low, b_high, i)) {
			return b[b_mid];
		}
	}
}


float median(vector<int> &a, vector<int> &b) {
	//O(m + n)
	//store in 3rd array in sorted fashion

	// a.last < b.first

	//find the index of current number
	//i + 2 (2nd)
	//pos

	// (m + n) if odd then central
	// if sum of two even central / 2
	// index mean combined array index
	// log(n)

	// 1st index -> O(log(n))
	// 2nd index -> O(log(n))

	// find the kth number in both arrays using binary search

	if ((m + n) % 2 == 1) { //return middle element
		return nth(a, b, (m + n) / 2);
	}
	return (nth(a, b, (m + n) / 2) + nth(a, b, (m + n - 1) / 2)) / 2.00;
}
 
void solve()
{
	cin >> m >> n;
	vector<int> a(m), b(n);
	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	// cout << check(1, b, a, 0, 1, 1);
	cout << median(a, b);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}