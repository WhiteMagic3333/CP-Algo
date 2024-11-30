#include<bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
multiset<int> s;
int n,a,c=0;
cin>>n;
while(n--)
{
cin>>a;
auto p=s.lower_bound(a+1);
if(p!=s.end())
{
    s.erase(p);
    s.insert(a);
}
else
{
    s.insert(a);
    c++;
}
}
cout<<c;
}