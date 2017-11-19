#include <iostream>
#include <fstream>
#define NM 200005
using namespace std;
ifstream in("mts.in");
ofstream out("mts.out");
int n,k,t,st,ct,nr,nrmax,dr,sdr,sst,scur;
long long s[NM],x[NM];
int main()
{
    in>>n>>k>>t;
    for(int i=1;i<=n;++i)
    {
        in>>s[i];
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;++i)in>>x[i];
    st=k;
    while(s[k]-s[st-1]+x[k]-x[st]<=t && st>0)--st;
    ++st;
    nrmax=k-st+1;
    dr=k;
    while(st<=k)
    {
        do
        {
            ++dr;
            if(dr<=n)
            {
                sst=s[dr]-s[st-1]+2*(x[k]-x[st])+x[dr]-x[k];
                sdr=s[dr]-s[st-1]+x[k]-x[st]+2*(x[dr]-x[k]);
                scur=min(sdr,sst);
            }
        }
        while(scur<=t && dr<=n);
        dr--;
        nrmax=max(dr-st+1,nrmax);
        ++st;
    }
    out<<nrmax;
    return 0;
}
