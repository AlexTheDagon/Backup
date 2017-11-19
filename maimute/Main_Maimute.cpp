#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define NM 100005
using namespace std;
ifstream in("maimute.in");
ofstream out("maimute.out");
vector<int> v[NM];
int x,y,h[NM],viz[NM],sem,n,m,caut,surs;
void dfsa(int nod)
{
    viz[nod]=1;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            h[i]=h[nod]+1;
            dfsa(i);
        }
    }
}
void dfs(int nod)
{
    if(nod==caut)
    {
        sem=1;
        return;
    }
    for(auto i:v[nod])
        if(h[i]<h[nod] && sem==0)dfs(i);
}
int main()
{
    in>>n;
    for(int i=1;i<n;++i)
    {
        in>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    h[1]=1;
    dfsa(1);
    in>>m;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y;
        surs=x;
        caut=y;
        sem=0;
        dfs(surs);
        if(sem)out<<"DA"<<'\n';
        else
        {
            swap(surs,caut);
            sem=0;
            dfs(surs);
            if(sem)out<<"DA"<<'\n';
            else out<<"NU"<<'\n';
        }
    }
    return 0;
}
