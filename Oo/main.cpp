#include <iostream>
#include <fstream>
using namespace std;
ifstream in("oo.in");
ofstream out("oo.out");
int cmax1[100005],n,a[100005],cmax3[100005],cmax2[100005],maxx;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    cmax1[1]=a[1]+a[n];
    for(int i=2;i<n-1;++i)
    {
        for(int j=i-3;j>=0 && j>=i-5;--j)
        {
            cmax1[i]=max(cmax1[i],cmax1[j]+a[i]+a[i-1]);
        }
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=i-3;j>=0 && j>=i-5;--j)
        {
            cmax2[i]=max(cmax2[i],cmax2[j]+a[i]+a[i-1]);
        }
    }
    cmax3[2]=a[1]+a[2];
    for(int i=3;i<n;++i)
    {
        for(int j=i-3;j>=0 && j>=i-5;--j)
        {
            cmax3[i]=max(cmax3[i],cmax3[j]+a[i]+a[i-1]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        maxx=max(maxx,cmax1[i]);
        maxx=max(maxx,cmax2[i]);
        maxx=max(maxx,cmax3[i]);
    }
    out<<maxx;
    return 0;
}
