#include <iostream>
#include <stdlib.h>
using namespace std;
long long n,m,a[100001],b[100002],i,j,c[100001],l;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=m;++i)cin>>b[i];
    b[i]=-1000000000;
    if(a[i-1]<0)b[i]=1000000000;
    i=1;
    j=1;
    while(j<=m && i<=n)
    {
        if(abs(a[i]-b[j])<=abs(a[i]-b[j+1]))
        {
            c[i]=abs(a[i]-b[j]);
            ++i;
        }
        else
        {
            ++j;
        }
    }
    for(int i=1;i<=n;++i)l=max(c[i],l);
    cout<<l;
    return 0;
}
