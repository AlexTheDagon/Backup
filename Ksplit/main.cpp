#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("ksplit.in");
ofstream out("ksplit.out");
int lmax,a[100005],sp[100005],minn=1000000000,maxx=-1000000000,s,f,smax=maxx,imin,n,sinainte=1000000000,sdupa=1000000000,iinceput,ifinal;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        sp[i]=a[i]+sp[i-1];
    }
    for(int i=2;i<n;++i)
    {
        if(minn>sp[i-1])
        {
            imin=i-1;
            minn=sp[i-1];
        }
        if(sp[i]-minn>smax)
        {
            s=imin+1;
            f=i;
            smax=sp[i]-minn;
        }
    }
    for(int i=0;i<s-1;++i)
    {
        if(sinainte>sp[s-1]-sp[i])
        {
            iinceput=i;
            sinainte=sp[s-1]-sp[i];
        }
    }
    for(int i=f+1;i<=n;++i)
    {
        if(sdupa>sp[i]-sp[f])
        {
            ifinal=i;
            sdupa=sp[i]-sp[f];
        }
    }
    if(sinainte<sdupa)
    {
        smax=smax-sinainte;
        if(sdupa>0)
        {
            smax=smax+sdupa;
            f=ifinal;
        }
        lmax=f-iinceput;
    }
    else
    {
        if(sinainte>sdupa)
        {
            smax=smax-sdupa;
            if(sinainte>0)
            {
                smax=smax+sinainte;
                s=iinceput+1;
            }
            lmax=ifinal-s+1;
        }
        else
        {
            smax=smax-sdupa;
            if(sdupa<0)
            {
                lmax=ifinal-s+1;
            }
            else
            {
                smax=smax+sdupa;
                lmax=ifinal-s+2;

            }
        }
    }
    if(n>2)out<<smax<<'\n'<<lmax;
    else out<<abs(a[1]-a[2])<<'\n'<<"2";
    return 0;
}
