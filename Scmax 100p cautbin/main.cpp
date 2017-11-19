#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("scmax.in");
ofstream out("scmax.out");
int n,s[NM],a[NM],best[NM],pre[NM],poz,nr,k,maxx;
void afis(int x)
{
    if(pre[x]>0)afis(pre[x]);
    out<<a[x]<<" ";
}
int caut(int x)
{
    int dr=nr,st=0,mid;
    while(st<=dr)
    {
        mid=(dr+st)/2;
        if(a[s[mid]]<x && a[s[mid+1]]>=x)return mid;
        else
        {
            if(a[s[mid+1]]<x)st=mid+1;
            else dr=mid-1;
        }
    }
    return nr;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    nr=1;
    best[1]=s[1]=1;
    for(int i=2;i<=n;++i)
    {
        poz=caut(a[i]);
        pre[i]=s[poz];
        best[i]=poz+1;
        s[poz+1]=i;
        if(nr<poz+1)nr=poz+1;
    }
    ///de aici ii bine
    for(int i=1;i<=n;++i)
    {
        if(best[i]>maxx)
        {
            maxx=best[i];
            poz=i;
        }
    }
    out<<maxx<<'\n';
    afis(poz);
    return 0;
}
///s[i]---cel mai mic nr cu care se termina un sir de lungime i
