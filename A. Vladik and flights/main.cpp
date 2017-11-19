#include <iostream>
#include <string>
using namespace std;
string s;
int a,b,dist,n,dmina,dminb;
int main()
{
    cin>>n>>a>>b>>s;
    --a;
    --b;
    if(a>b)swap(a,b);
    if(s[a]!=s[b])
    {
        dmina=10000000;
        dminb=10000000;
        for(int i=b;i<n;++i)if(s[a]==s[i])dminb=min(dminb,i-b);
        for(int i=b;i>=a;+--i)if(s[a]==s[i])dminb=min(dminb,b-i);
        for(int i=a;i<b;++i)if(s[b]==s[i])dmina=min(dmina,i-a);
        for(int i=a;i>=0;--i)if(s[b]==s[i])dmina=min(dmina,a-i);
        cout<<min(dmina,dminb);
    }
    else cout<<"0";
    return 0;
}
