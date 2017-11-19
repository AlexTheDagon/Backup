#include <iostream>
#include <fstream>
using namespace std;
ifstream in("bursa.in");
ofstream out("bursa.out");
long long p[100001],s,n,maxx,minn,minim[100002],sprim;
int main()
{
    in>>n>>s;
    sprim=s;
    minn=100000000000;
    p[0]=100000000000;
    for(int i=1;i<=n;++i)
    {
        in>>p[i];
        if(p[i]<minn)minn=p[i];
        if(p[i]>maxx)maxx=p[i];
        else
        {
            minn=p[i];
            maxx=p[i];
        }
        minim[i]=minn;
    }
    maxx=0;
    for(int i=1;i<=n;++i)
    {
        if(maxx<=p[i])maxx=p[i];
        else
        {
            s=s%minim[i-1]+s/minim[i-1]*maxx;
            maxx=0;
        }
    }
    if(p[n]>p[n-1])s=s%minim[n]+s/minim[n]*maxx;
    out<<s-sprim;
    return 0;
}
