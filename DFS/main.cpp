#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("dfs.in");
ofstream out("dfs.out");
int a,b,grupe,n,m,viz[NM];
queue <int> q;
vector <int> v[NM];
void dfs(int nod)
{
    for(int i=0;i<v[nod].size();++i)
    {
        if(viz[v[nod][i]]==0)
        {
            viz[v[nod][i]]=1;
            dfs(v[nod][i]);
        }
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
    {
        if(viz[i]==0)
        {
            ++grupe;
            dfs(i);
        }
    }
    out<<grupe;
    return 0;
}
