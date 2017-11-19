#include <iostream>
#include <fstream>
using namespace std;
ifstream in("joc10.in");
ofstream out("joc10.out");
int et[405],vic[405],n,m,viz[905],etape,ind,minn=10000000,elim,incap[405],a[905];
int main()
{
    in>>n>>m;
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=m;++i)
        {
            in>>a[i];
            viz[i]=0;
        }
        ind=1;
        etape=1;
        while(a[ind]!=0 && a[ind]!=9999 && viz[ind]==0)
        {
            ++etape;
            etape+=a[ind]%10;
            viz[ind]=1;
            ind=a[ind]/10;
        }
        if(a[ind]==0)vic[k]=-1;
        else
        {
            if(a[ind]==9999)
            {
                vic[k]=1;
                incap[k]=ind;
            }
            else vic[k]=-2;
        }
        et[k]=etape;
    }
    for(int i=1;i<=n;++i)
    {
        if(vic[i]==1 && et[i]<minn)
        {
            ind=i;
            minn=et[i];
        }
    }
    for(int i=1;i<=n;++i)if(vic[i]==-1 && et[i]<=minn)++elim;
    out<<ind<<" "<<incap[ind]<<" "<<minn<<" "<<elim<<'\n';
    return 0;
}
