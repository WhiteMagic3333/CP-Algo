class Solution {
public:
    int n,m,dp[1000][5][(1<<10)],mod=1e9+7;
    
    int sol(int i,int j,int mask)
    {
        if(i==n) return 1;
        if(j==m) return sol(i+1,0,mask);
        
        long ans=dp[i][j][mask];
        if(ans!=-1) return ans;
        ans=0;
        
        for(int k=1;k<=3;k++)
        {
            int t=((1<<10)-1) ^ (3<<2*j);   // 11 11 00(jth 00) 11 11
            int nwmask=(mask & t) ^ (k<<2*j);   // change mask = 01 10 00(jth 00) 11 10  ^  00 00 k 00 00  
            
            int up=(mask>>(2*j))%4; // mask's jth value in (i-1)'s row
            int lst=0;
            if(j) lst=(mask>>(2*(j-1)))%4;  //  mask's (j-1)th value i ith row; 
            
            if(k==up || k==lst) continue;
            ans+=sol(i,j+1,nwmask);
        }
        ans%=mod;
        return dp[i][j][mask]=ans;
    }
    
    int colorTheGrid(int mm, int nn) 
    {
        n=nn; m=mm;
        memset(dp,-1,sizeof(dp));
        return sol(0,0,0);
    }
};