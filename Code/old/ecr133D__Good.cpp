    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define mod 998244353
     
     
    int curr[200005];
    int ans[200005];
    int curr_next[200005];
     
    int32_t main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
     
        int n,k;
        memset(curr,0,sizeof(curr));
        memset(ans,0,sizeof(ans));
        memset(curr_next,0,sizeof(curr_next));
        curr[0]=1;
        cin>>n>>k;
        for(int i=0;i<720;i++)
            {
                for(int j=0;j<200005;j++)
                    {
                        ans[j]+=curr[j];
                        ans[j]%=mod;
                    }
                int step=k+i;
                for(int j=0;j<200005;j++)
                    {
                        curr_next[j]=0;
                        if(j>=step){curr_next[j]+=curr_next[j-step];curr_next[j]+=curr[j-step];curr_next[j]%=mod;}
                    }
                for(int j=0;j<200005;j++){curr[j]=curr_next[j];}
            }
        for(int i=1;i<=n;i++){cout<<ans[i]<<" ";}
    }