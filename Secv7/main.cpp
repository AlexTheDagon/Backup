#include <iostream>
#include <fstream>
using namespace std;
ifstream in("secv7.in");
ofstream out("secv7.out");
int md[30005],ms[30005],a[30005],n,smax=1000000000,i1,i2;
void reset()
{
    for(int i=1;i<=n;++i)md[i]=ms[i]=0;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    ///caz 1
    for(int i=2;i<=n;++i)ms[i]=max(ms[i-1],a[i]);
    for(int i=n;i>1;--i)md[i]=max(md[i+1],a[i]);
    for(int i=2;i<n;++i)
    {
        if(smax>a[1]+ms[i]+md[i+1])
        {
            i1=1;
            i2=i;
            smax=a[1]+ms[i]+md[i+1];
        }
    }
    reset();
    ///caz2
    for(int i=1;i<n;++i)ms[i]=max(ms[i-1],a[i]);
    for(int i=n;i>0;--i)md[i]=max(md[i+1],a[i]);
    for(int i=1;i<n-1;++i)
    {
        if(smax>a[n]+ms[i]+md[i+1])
        {
            i1=i;
            i2=n-1;
            smax=a[n]+ms[i]+md[i+1];
        }
    }
    reset();
    ///caz3
    for(int i=1;i<n;++i)ms[i]=max(ms[i-1],a[i]);
    for(int i=n;i>0;--i)md[i]=max(md[i+1],a[i]);
    for(int i=1;i<n-1;++i)
    {
        if(smax>ms[i]+a[i+1]+md[i+2])
        {
            smax=ms[i]+a[i+1]+md[i+2];
            i1=i;
            i2=i+1;
        }
    }
    out<<smax<<'\n';
    out<<i1<<" "<<i2;
    return 0;
}
