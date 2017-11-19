#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#define pb push_back
#define NM 100005
#define f first
#define s second
#define mp make_pair
using namespace std;
ifstream in("bal.in");
ofstream out("bal.out");
map<pair<int,int>,int> mm;
int m,n,x,y,sem,viz[2][NM],sol[NM],fol[NM],indfs[2][NM];
vector<int> v[2][NM];
void dfs(int nod,int par,int sex)///0 baiat,1 fata
{
    if(sem==1)return;
    viz[sex][nod]=1;
    indfs[sex][nod]=1;
    for(auto i:v[sex][nod])
    {
        if(indfs[1-sex][i] && i!=par)sem=1;
        if(i!=par && !viz[1-sex][i])
        {
                dfs(i,nod,1-sex);
        }
    }
    if(sex==1 && sol[par]==0 && fol[nod]==0)
    {
        sol[par]=nod;
        fol[nod]=1;
    }
    else
    {
        if(sex==0  && sol[nod]==0 && fol[par]==0)
        {
            sol[nod]=par;
            fol[par]=1;
        }
    }
    indfs[sex][nod]=0;
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y;
        if(mm.find(mp(x,y))==mm.end())
        {
            v[0][x].pb(y);
            v[1][y].pb(x);
        }
    }
    for(int i=1;i<=n;++i)if(v[0][i].size()==0 || v[1][i].size()==0)sem=1;
    for(int i=1;i<=n;++i)
    {
        if(!viz[0][i])dfs(i,0,0);
    }
    if(sem)out<<"NU";
    else
    {
        out<<"DA"<<'\n';
        for(int i=1;i<=n;++i)out<<sol[i]<<'\n';
    }
    return 0;
}
