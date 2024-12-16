#include <bits/stdc++.h>
using namespace std;
 
int fact(int n){
    if(n==0 || n==1)
    return 1;
    else
    return n*fact(n-1);
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        int r = 10-n;
        int c = 2;
        cout<<(fact(r)/(fact(c)*fact(r-c)))*6<<endl;
    }
}