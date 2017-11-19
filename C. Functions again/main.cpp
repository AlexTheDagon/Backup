#include <iostream>
#include <cstdlib>
using namespace std;
long long n,a[100005],s,smax,ap[100005],an[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<n;++i)
    {
        ap[i]=abs(a[i]-a[i+1]);
        if(i%2==0)ap[i]*=-1;
    }
    for(int i=1;i<n;++i)
    {
        an[i]=abs(a[i]-a[i+1]);
        if(i%2==1)an[i]*=-1;
    }
    for(int i=1;i<n;++i)
    {
        if(s<0)s=0;
        s+=ap[i];
        smax=max(smax,s);
    }
    s=0;
    for(int i=1;i<n;++i)
    {
        if(s<0)s=0;
        s+=an[i];
        smax=max(smax,s);
    }
    cout<<smax;
    return 0;
}
