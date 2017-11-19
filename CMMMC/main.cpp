#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("cmmmc.in");
ofstream out("cmmmc.out");
int t,x,l1,l2,k,lim,sol1,sol2,A[30],aux;
int d[25000];
bool ciur[200000];
void gen(int pas,int limita)
{
    if(pas>limita)
    {
        if(sol1+aux/sol1<l1+l2)
        {
            l1=min(sol1,aux/sol1);
            l2=aux/l1;
        }
    }
    else
    {
        for(int i=pas;i<=limita;++i)
        {
            sol1*=A[i];
            gen(i+1,limita);
            sol1/=A[i];
        }
    }
}
int cmmdc(int a,int b)
{
    int c=0;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int perechi(int n)
{
    aux=n;
    int ii=1,dpr[30]={0},dpr2[30]={0},dpr3[30]={0},nrdiv=0,nr=1,limit;
    limit=sqrt(n)+1;
    while(d[ii]<=limit)
    {
        if(n%d[ii]==0)
        {
            ++nrdiv;
            dpr3[nrdiv]=1;
            while(n%d[ii]==0)
            {
                n=n/d[ii];
                ++dpr[nrdiv];
                dpr3[nrdiv]*=d[ii];
            }
        }
        ++ii;
    }
    if(n>1)
    {
        ++dpr[++nrdiv];
        dpr3[nrdiv]=n;
    }
    if(nrdiv>0)
    {
        nr=dpr[nrdiv]+1;
        dpr2[nrdiv+1]=1;
        for(int i=1;i<=nrdiv;++i)dpr2[i]=dpr[i]*2+1;
        for(int i=nrdiv-1;i>0;--i)dpr2[i]*=dpr2[i+1];
        for(int i=nrdiv-1;i>0;--i)nr+=(dpr2[i+1]*dpr[i]);
    }
    l1=l2=1000000000;
    for(int i=0;i<30;++i)A[i]=dpr3[i];
    sol1=1;
    sol2=1;
    gen(1,nrdiv);
    return nr;
}




void c()
{
    lim=sqrt(2000000000);
    for(int i=1;i<=lim;++i)ciur[i]=1;
    for(int i=2;i<=lim;++i)
    {
        if(ciur[i]==1)
        {
            d[++k]=i;
            for(int j=i+i;j<=lim;j+=i)ciur[j]=0;
        }
    }
}
int main()
{
    c();
    in>>t;
    for(int i=1;i<=t;++i)
    {
        l1=l2=2000000000;
        in>>x;
        out<<perechi(x)<<" ";
        out<<l1<<" "<<l2<<'\n';

    }

    return 0;
}
