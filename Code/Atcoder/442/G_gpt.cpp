#include<bits/stdc++.h>
#define int long long
const int N=2e6+10,M=50;
using namespace std;
struct Ty{
    int u,v,w;
    bool operator <(Ty a)const{return v*a.w>a.v*w;}
}x[N];
int n,m,y[N],f[M],g[M];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&x[i].w,&x[i].v,&x[i].u);
    sort(x+1,x+n+1);
    int res=0;
    for(int i=1;i<=n;i++){
        y[i]=min(x[i].u,m/x[i].w);
        res+=y[i]*x[i].v;
        m-=y[i]*x[i].w;
    }
    for(int i=0;i<=6;i++)f[i]=1e16;
    for(int i=0;i<=min(6ll,m);i++)f[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(6ll,y[i]);j++)for(int k=10;k>=x[i].w*j;k--)f[k]=min(f[k],f[k-x[i].w*j]+j*x[i].v);
        for(int j=1;j<=min(6ll,x[i].u-y[i]);j++)for(int k=10;k>=x[i].w*j;k--)g[k]=max(g[k],g[k-x[i].w*j]+j*x[i].v);
    }
    int ans=0;
    for(int i=0;i<=6;i++)ans=max(ans,res-f[i]+g[i]);
    printf("%lld\n",ans);
    return 0;
}