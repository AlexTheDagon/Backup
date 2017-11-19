#include <iostream>
#include <fstream>
#include <math.h>
#include <bitset>
#include <iomanip>
using namespace std;
ifstream in("ubercool.in");
ofstream out("ubercool.out");
long long x;
long long a,p,sem,t;
long long put;
bitset <32005> prim;
int main()
{
    for(int i=2;i<=32000;++i)prim[i]=1;
    for(int i=2;i<=32000;++i)
    {
        if(prim[i]==1)
        {
            ++p;
            for(int j=i*2;j<=32000;j=j+i)
            {
                prim[j]=0;
            }
        }
    }
    in>>t;
    for(int i=1;i<=t;++i)
    {
        in>>x;
        if(x>=4)
        {
            put=64;
            sem=0;
            while(put>5 && sem==0)
            {
                --put;
                a=(long long)(pow(x,float(1.0/put)));
                if(a==float(pow(x,float(1.0/put))))if(prim[a]==1)sem=1;
            }
            if(sem==0)
            {
                sem=1;
                a=(long long)(pow(x,float(1.0/3)));
                for(int j=2;j<=a/2;++j)
                {
                    if(a%j==0)sem=0;
                }
                if(sem==0){sem=1;
                a=sqrt(x);
                for(int j=2;j<=a/2;++j)
                {
                    if(a%j==0)sem=0;
                }}
            }
            if(sem)
            {
                out<<"DA"<<'\n';
            }
            else out<<"NU"<<'\n';
        }
        else out<<"NU"<<'\n';
    }
    return 0;
}

