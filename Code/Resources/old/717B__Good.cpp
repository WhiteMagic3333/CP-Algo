    #include<bits/stdc++.h>
    using namespace std;
     
    #define fast_io(x, y) ios_base::sync_with_stdio(x), cin.tie(y)
     
    bool solve(vector<int> &v, const int n)
    {	
    	for(int i = 0, x = 0; i < n - 1; ++i){
    		x ^= v[i];
    		bool found = false;
    		int y = 0;
    		for(int j = i + 1; j < n; ++j){
    			y ^= v[j];
    			if(y == x){
    				found = true;
    				y = 0;
    			}
    		}
    		if(found && !y)
    			return true;
    	}
    	return false;
    }
     
    int main()
    {
    	fast_io(false, nullptr);
    	int T;
    	cin >> T;
    	while(T--)
    	{
    		int n;
    		cin >> n;
    		vector<int> v( n );
    		for(int &x : v)
    			cin >> x;
    		puts(solve( v, n )  ? "YES" : "NO");
    	}
    	return 0;
    }