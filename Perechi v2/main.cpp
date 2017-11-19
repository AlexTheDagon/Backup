#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("perechi.in");
ofstream out("perechi.out");
long long  n,d,dprimi[30],dpr[30],diviz,limit,p,nr=1;
int main()
{
    in>>n;
    d=2;
    diviz=1;
    limit=sqrt(n);
    while(d<=limit+1 && d<=n)
    {
        while(n%d==0)
        {
            ++dprimi[diviz];
            n/=d;
        }
        ++d;
        if(dprimi[diviz]!=0)++diviz;
    }
    if(n>1)out<<nr+1;///numar prim
    else
    {
        d=diviz;
        nr+=dprimi[d];
        dpr[d]=dprimi[d]*2+1;
        for(int i=d-1;i>0;--i)dpr[i]=dpr[i+1]*dprimi[i];
        for(int i=d-1;i>0;--i)nr+=(dprimi[i]*dpr[i+1]);
        out<<nr;
    }
    return 0;
}
