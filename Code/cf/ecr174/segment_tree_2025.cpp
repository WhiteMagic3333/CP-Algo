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

//for storing sum
struct Node {
	int sum;
	Node () {
		sum = 0;
	}
};

Node merge (Node a, Node b) {
	Node ans;
	ans.sum = a.sum + b.sum;
	return ans;
}

int mx_sz = 2e5 + 1;

vector<Node> t(4 * mx_sz);

void build(int id, int l, int r) {
	if (l == r) {
		t[id].sum = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
	if (pos < l || pos > r) {
		return;
	} else if (l == r) {
		t[id].sum += val;
		return;
	}
	int mid = l + (r - l) / 2;
	update(2 * id, l, mid, pos, val);
	update(2 * id + 1, mid + 1, r, pos, val);
	t[id] = merge(t[2 * id], t[2 * id + 1]);
}

Node query(int id, int l, int r, int low, int high) {
	//using range intersect
	if (low > r || high < l) {
		return Node();//imp line
	}

	if (lq <= l && r <= rq) {
		
	}

	int mid = l + (r - l) / 2;
	return merge(query(2 * id, l, mid, low, high), query(2 * id + 1, mid + 1, r, low, high));
}
 
void solve()
{
	
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}