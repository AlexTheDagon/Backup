#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmmdc2.in");
ofstream out("cmmdc2.out");
int fr[1000005],a[1000005],k,n,x,ult,fra,maxx,d,r,sol[100005],ind;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        ++fr[a[i]];
        maxx=max(maxx,a[i]);
    }
    for(int i=maxx;d==0;--i)
    {
        fra=0;
        for(int j=i;j<=maxx;j+=i)
        {
            fra+=fr[j];
            if(fr[j])if(fra>=k)ult=j;
        }
        if(fra>=k)d=i;
    }
    out<<d<<'\n';
    r=k;
    while(r)
    {
        while(fr[ult] && r)
        {
            --fr[ult];
            sol[--r]=ult;
        }
        ult-=d;
    }
        for(int i=k-1;i>=0;--i)out<<sol[i]<<" ";
    return 0;
}
