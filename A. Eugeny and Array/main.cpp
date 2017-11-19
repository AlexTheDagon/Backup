#include <iostream>

using namespace std;
int p,n,x,k,m,l,r;
int main()
{
    cin>>k>>m;
    for(int i=1;i<=k;++i)
    {
        cin>>x;
        if(x==1)++p;
        else ++n;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>l>>r;
        if((r-l+1)%2==0 && (r-l+1)/2<=p && (r-l+1)/2<=n)cout<<"1";
        else cout<<"0";
        cout<<'\n';
    }
    return 0;
}
