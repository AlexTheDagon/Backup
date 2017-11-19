#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("ksplit.in");
ofstream out("ksplit.out");
int n,lmax,a[NM];
int pozmax[NM],pozmin[NM];
long long maxx=-1<<30,smax[NM],smin[NM];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    smax[1]=a[1];
    pozmax[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(smax[i-1]>=0)
        {
            smax[i]=a[i]+smax[i-1];
            pozmax[i]=pozmax[i-1];
        }
        else
        {
            smax[i]=a[i];
            pozmax[i]=i;
        }
    }
    smin[n-1]=a[n];
    pozmin[n-1]=n;
    for(int i=n-2;i>0;--i)
    {
        if(-smin[i+1]>=0)
        {
            smin[i]=a[i+1]+smin[i+1];
            pozmin[i]=pozmin[i+1];
        }
        else
        {
            smin[i]=a[i+1];
            pozmin[i]=i+1;
        }
    }
    for(int i=1;i<n;++i)
    {
        long long x=smax[i]-smin[i];
        if(x>maxx)
        {
            maxx=x;
            lmax=pozmin[i]-pozmax[i];
        }
    }///suma de la stanga la dreapta
    for(int i=1;i<=n;++i)
    {
        smax[i]=0;
        smin[i]=0;
        pozmin[i]=0;
        pozmax[i]=0;
    }///curatare siruri
    smax[1]=a[1];
    pozmax[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(-smax[i-1]>=0)
        {
            smax[i]=a[i]+smax[i-1];
            pozmax[i]=pozmax[i-1];
        }
        else
        {
            smax[i]=a[i];
            pozmax[i]=i;
        }
    }
    smin[n-1]=a[n];
    pozmin[n-1]=n;
    for(int i=n-2;i>0;--i)
    {
        if(smin[i+1]>=0)
        {
            smin[i]=a[i+1]+smin[i+1];
            pozmin[i]=pozmin[i+1];
        }
        else
        {
            smin[i]=a[i+1];
            pozmin[i]=i+1;
        }
    }
    for(int i=1;i<n;++i)
    {
        long long x=smin[i]-smax[i];
        if(x>maxx)
        {
            maxx=x;
            lmax=pozmin[i]-pozmax[i];
        }
    }///suma de la dreapta la stanga
    out<<maxx<<'\n';
    out<<lmax+1;
    return 0;
}





