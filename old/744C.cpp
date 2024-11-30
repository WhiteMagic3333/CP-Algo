    #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<array>
    #include<map>
    #include<numeric>
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
    int n, m, k;
     
    int mark(vector<vector<char>> &arr, vector<vector<bool>> &vis, int i, int j, int level)
    {
    	if(i < 0 || (j - level) < 0 || (j + level) >= m)
    		return 0;
    	if(arr[i][j - level] != '*' || arr[i][j + level] != '*')
    		return 0;
    	vis[i][j - level] = vis[i][j + level] = true;
    	return 1 + mark(arr, vis, i - 1, j, level + 1);
    }
    int check(vector<vector<char>> &arr, vector<vector<bool>> &vis, int i, int j, int level)
    {
    	if(i < 0 || (j - level) < 0 || (j + level) >= m)
    		return 0;
    	if(arr[i][j - level] != '*' || arr[i][j + level] != '*')
    		return 0;
    	return 1 + check(arr, vis, i - 1, j, level + 1);
    }
     
    void solve()
    {
    	cin >> n >> m >> k;
    	vector<vector<char>> arr(n, vector<char> (m, ' '));
    	for (int i = 0; i < n; i++)
    		cin >> arr[i];
    	vector<vector<bool>> vis(n, vector<bool> (m, false));
    	int cur = 1e5;
    	for (int i = n - 1; i >= 0; i--)
    	{
    		for(int j = 0; j < m; j++)
    		{
    			if(arr[i][j] == '*'){
    				if(check(arr, vis, i - 1, j, 1) >= k){
    					vis[i][j] = true;
    					mark(arr, vis, i - 1, j, 1);
    				}
    			}
    		}
    	}
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < m; j++)
    		{
    			if(arr[i][j] == '*' && vis[i][j] == false)
    				return void(cout << "NO");
    		}
    	}
    	cout << "YES";
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