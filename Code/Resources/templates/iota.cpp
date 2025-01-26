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
 
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n), order(n);
	cin >> arr;
	iota(order.begin(), order.end(), 0LL);
	sort(order.begin(), order.end(), [&] (int a, int b) {
		return arr[a] < arr[b];
	});
	// store the index of element that is supposed be at this pos
	// eg
	// 5
	// 5 1 3 2 4
	// 1 3 2 4 0
	cout << order;
}
 
int main()
{
	//CAP theorem, indexing, multithreading how to create and start thread
	//Type of database -NoSQL, SQL and InMemory
	//Apache-kafka, redis, messaging queue, RabbitMQ
	//Websockets?
	//Databases Partitioning and Sharading
	//backend.sh and systemdesign.sh

	//Error Handling? try catch exception throws


	// Graph Theory
	// 

	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}