#include <iostream>
#include <fstream>
using namespace std;
ifstream in("arc.in");
ofstream out("arc.out");
int pre,act,cul[20005],elem[20005],n,nrsec,caz,maxx,poz,r,bile,parsate,ii,jj,aux;
int main()
{
    in>>caz;
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>act;
        if(act!=pre)++nrsec;
        cul[nrsec]=act;
        ++elem[nrsec];
        pre=act;
    }
    if(caz==1)out<<nrsec<<'\n';
    else
    {
        for(int i=1;i<=nrsec;++i)
        {
            if(elem[i]>maxx)
            {
                maxx=elem[i];
                poz=i;
            }
        }
        while(maxx>2)
        {
            r=1;
            ii=poz-1;
            jj=poz+1;
            while(cul[ii]==cul[jj] && ii>=1 && jj<=nrsec && elem[ii]+elem[jj]>2)
            {
                --ii;
                ++jj;
            }
            if(jj>nrsec)nrsec=ii;
            else
            {
                if(ii>=1 && jj<=nrsec && cul[ii]==cul[jj])
                {
                    elem[ii]+=elem[jj];
                    ++jj;
                }
                aux=nrsec-jj+ii+1;
                ++ii;
                while(jj<=nrsec)
                {
                    elem[ii]=elem[jj];
                    cul[ii]=cul[jj];
                    ++ii;
                    ++jj;
                }
                nrsec=aux;
            }
            maxx=0;
            for(int i=1;i<=nrsec;++i)
            {
                if(elem[i]>maxx)
                {
                    maxx=elem[i];
                    poz=i;
                }
            }
        }
        if(nrsec<=0)out<<"0";
        else
        {
            for(int i=1;i<=nrsec;++i)
            {
                bile+=elem[i];
            }
            out<<bile<<'\n';
            for(int i=1;i<=nrsec;++i)
            {
                for(int j=1;j<=elem[i];++j)out<<cul[i]<<'\n';
            }
        }
    }
    return 0;
}
