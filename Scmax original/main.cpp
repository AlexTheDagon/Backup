#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 100005
using namespace std;
ifstream in("scmax.in");
ofstream out("scmax.out");
int scmax[NM],ind_cur[NM],ind_parinte[NM],n,a[NM],pozitie,lungime_scmax;
void refacere(int ind_refacere)
{
    if(ind_parinte[ind_refacere]!=0)
        refacere(ind_parinte[ind_refacere]);
    out<<a[ind_refacere]<<" ";
}
int cauta(int st,int dr,int val)
{
    int hi=dr,low=st,mid;
    while(low<=hi)
    {
        mid=(hi+low)/2;
        if(scmax[mid-1]<val && scmax[mid]>=val)return mid;
        else
        {
            if(scmax[mid]<=val)low=mid+1;
            else hi=mid-1;
        }
    }
    return low;
}
int main()
{
    in>>n;
    for(int i=1;i<=n+2;++i)scmax[i]=(1<<30);
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        pozitie=cauta(1,lungime_scmax,a[i]);
        ind_parinte[i]=ind_cur[pozitie-1];
        ind_cur[pozitie]=i;
        scmax[pozitie]=a[i];
        if(pozitie>lungime_scmax)++lungime_scmax;
    }
    out<<lungime_scmax<<'\n';
    refacere(ind_cur[lungime_scmax]);
    return 0;
}
