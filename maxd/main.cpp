#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("maxd.in");
ofstream out("maxd.out");
int st,dr,copie,limit,nr,d;
bool ciur[50005];
int divv[6000],lg=-1;
int dmax,minn,nrdivmax,nrdiv;
int main()
{
    in>>st>>dr;
    for(int i=1;i<=50000;++i)ciur[i]=1;
    for(int i=2;i<=50000;++i)
    {
        if(ciur[i])
        {
            divv[++lg]=i;
            for(int j=2*i;j<=50000;j+=i)ciur[j]=0;
        }
    }
    for(int i=st;i<=dr;++i)
    {
        copie=i;
        limit=sqrt(i)+2;
        nrdiv=1;
        for(d=0;divv[d]<limit && copie!=1;++d)
        {
            while(copie%divv[d]==0)
            {
                ++nr;
                copie/=divv[d];
            }
            nrdiv*=(nr+1);
            nr=0;
        }
        if(copie!=1)nrdiv*=2;
        if(nrdiv>dmax)
        {
            dmax=nrdiv;
            minn=i;
            nrdivmax=0;
        }
        if(nrdiv==dmax)++nrdivmax;
    }
    out<<minn<<" "<<dmax<<" "<<nrdivmax;
    return 0;
}
