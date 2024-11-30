#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
 
 
 
int seive[300005];
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
 
 
    memset(seive,0,sizeof(seive));
 
    for(int i=2;i<300005;i++)
        {
            if(seive[i]==0)
                {
                    seive[i]=i;
                    for(int j=i*i;j<300005;j+=i)
                        {
                            seive[j]=i;
                        }
                }
        }
 
    int n,m;
    cin>>n>>m;
    int dp[n+1];
    //of ;en i
 
    dp[1]=m;
    dp[1]%=mod;
    int pro=1;
    int bound=1e13;
    for(int i=2;i<=n;i++)
        {
            if(seive[i]==i){pro*=i;pro=min(pro,bound);}
            int h=dp[i-1];
            int poss=(m/pro);
            poss%=mod;
            h*=poss;
            h%=mod;
            dp[i]=h;
        }
 
    int ans=0;
    for(int i=1;i<=n;i++){ans+=dp[i];ans%=mod;}
 
    int tot=0;
    int curr=1;
    for(int i=1;i<=n;i++)
        {
            int pp=m%mod;
            curr*=pp;
            curr%=mod;
            tot+=curr;
            tot%=mod;
        }
    cout<<(tot+mod-ans)%mod;
}