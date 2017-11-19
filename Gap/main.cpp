#include <iostream>
#include <fstream>
using namespace std;
ifstream in("gap.in");
ofstream out("gap.out");
int fr[20],cmin,cmax;
long long x,t,dmax;
long long genmin(int cif)
{
    long long nr=cif;
    int aux;
    --fr[cif];
    for(int i=9;i>=0;--i)
    {
        aux=fr[i];
        while(aux)
        {
            nr=nr*10+i;
            --aux;
        }
    }
    ++fr[cif];
    return nr;
}
long long genmax(int cif)
{
    long long nr=cif;
    int aux;
    --fr[cif];
    for(int i=0;i<10;++i)
    {
        aux=fr[i];
        while(aux)
        {
            nr=nr*10+i;
            --aux;
        }
    }
    ++fr[cif];
    return nr;
}
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>x;
        dmax=0;
        for(int i=0;i<=10;++i)fr[i]=0;
        while(x)
        {
            ++fr[x%10];
            x/=10;
        }
        cmax=9;
        while(cmax>0)
        {
            if(fr[cmax]!=0)
            {
                cmin=cmax-1;
                while(fr[cmin]==0 && cmin>0)--cmin;
                if(fr[cmin]!=0)
                {
                    dmax=max(dmax,genmax(cmax)-genmin(cmin));
                }
            }
            --cmax;
        }
        out<<dmax<<'\n';
    }
    return 0;
}
