#include <iostream>
#include <fstream>
#include <algorithm>
#define NM 105
#define MM 15005
using namespace std;
ifstream in("numar2.in");
ofstream out("numar2.out");
int a[NM],lim,prod[MM],n,m,nrp,st,dr,mij,vmij;
void back(int pas,int nrelem,long long p)
{
    if(nrelem%2==1)prod[++nrp]=p;
    else prod[++nrp]=-p;
    if(pas>n)return;
    for(int i=pas;i<=n;++i)
        if(p*a[i]<=lim)
            back(i+1,nrelem+1,p*a[i]);
}
int verif(int nr)
{
    int val=0;
    for(int i=1;i<=nrp;++i)
        val+=nr/prod[i];
    return val;
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)in>>a[i];
    lim=m*a[1]+1;
    for(int i=1;i<=n;++i)
        back(i+1,1,a[i]);
    sort(prod+1,prod+nrp+1);
    st=0;
    dr=lim;
    while(dr>=st)
    {
        mij=(dr+st)/2;
        vmij=verif(mij);
        if(vmij==m)break;
        if(vmij>m)dr=mij-1;
        else st=mij+1;
    }
    int sem=0;
    ++mij;
    while(sem==0)
    {
        --mij;
        for(int i=1;i<=n;++i)if(mij%a[i]==0)sem=1;
    }
    out<<mij;
    return 0;
}
