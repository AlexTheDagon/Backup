#include <iostream>

using namespace std;
int n,m,a,b,nmin,nmax,mmin,mmax,s;
int main()
{
    cin>>n;
    nmin=1000000010;
    mmin=1000000010;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        nmin=min(nmin,b);
        nmax=max(nmax,a);
    }
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        mmin=min(mmin,b);
        mmax=max(mmax,a);
    }
    s=max(mmax-nmin,nmax-mmin);
    if(s<0)s=0;
    cout<<s;
    return 0;
}
