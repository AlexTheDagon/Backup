#include <iostream>
#include <vector>
#include <fstream>
#define pb push_back
using namespace std;
ifstream in("pang.in");
ofstream out("pang.out");
int t,n,m,k,a,b;
vector <int> v[100005];
int viz[100005],nmax[100005],nextt[100005],sem[100005],semm,nods,ramas;
void dfs(int s)
{
    viz[s]=1;
    for(auto i:v[s])
    {
        if(viz[i]==0)
        {
            dfs(i);
        }
        if(nmax[s]<nmax[i])
        {
            nmax[s]=nmax[i];
            nextt[s]=i;
        }
    }
    if(sem[s])++nmax[s];
}
int main()
{
    in>>t;
    for(int teste=0;teste<t;++teste)
    {
        in>>n>>m>>k;
        for(int i=1;i<=m;++i)
        {
            in>>a>>b;
            v[a].pb(b);
        }
        for(int i=1;i<=k;++i)
        {
            in>>a;
            sem[a]=1;
        }
        semm=0;
        for(int i=1;i<=n;++i)
        {
            if(viz[i]==0)
            {
                dfs(i);
                if(nmax[i]==k)
                {
                    semm=1;
                    nods=i;
                }
            }
        }
        if(semm==1)
        {
            out<<"Da"<<'\n';
            ramas=k;
            while(ramas)
            {
                if(sem[nods])
                {
                    out<<nods<<" ";
                    --ramas;
                }
                nods=nextt[nods];
            }
            out<<'\n';
        }
        else out<<"Nu"<<'\n';
        for(int i=1;i<=n;++i)
        {
            sem[i]=0;
            viz[i]=0;
            nmax[i]=0;
            nextt[i]=0;
            v[i].clear();
        }
    }
    return 0;
}
