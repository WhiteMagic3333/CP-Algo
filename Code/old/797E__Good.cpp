    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define mod 1000000007
     
     
     
     
    int32_t main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
     
        int t;
        cin>>t;
     
        while(t--)
            {
                int n,k;
                cin>>n>>k;
                int a[n];
                for(int i=0;i<n;i++){cin>>a[i];}
     
                int ans=0;
                for(auto x:a){ans+=(x/k);}
     
                multiset<int> s;
                for(int i=0;i<n;i++)
                    {
                        s.insert(a[i]%k);
                    }
     
                while(!s.empty())
                    {
                        auto it=s.end();
                        it--;
                        int y=*(it);
                        s.erase(s.find(y));
                        auto it2=s.lower_bound(k-y);
                        if(it2==s.end()){break;}
                        ans++;
                        s.erase(it2);
                    }
                cout<<ans<<"\n";
            }
    }