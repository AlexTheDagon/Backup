#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("pluricex.in");
ofstream out("pluricex.out");
vector <int> elev[30];
int n,d,k,x,m,fr[20],team[10],sem;
void gen(int poz)
{
    for(int i=team[poz-1]+1;i<=n-k+poz;++i)
    {
        team[poz]=i;
        for(auto j:elev[team[poz]])++fr[j];
        if(poz==k)
        {
            sem=1;
            for(int ii=1;ii<=d;++ii)if(fr[ii]==0)sem=0;
            if(sem)
            {
                for(int ii=1;ii<=k;++ii)out<<team[ii]<<" ";
                out<<'\n';
            }
        }
        else gen(poz+1);
        for(auto j:elev[team[poz]])--fr[j];

    }
}
int main()
{
    in>>n>>k>>d;
    for(int i=1;i<=n;++i)
    {
        in>>m;
        for(int j=1;j<=m;++j)
        {
            in>>x;
            elev[i].pb(x);
        }
    }
    gen(1);
    return 0;
}
