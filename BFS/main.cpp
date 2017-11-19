#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define NM 100005
using namespace std;
ifstream in("bfs.in");
ofstream out("bfs.out");
int n,m,s,viz[NM],dist[NM],a,b,fr;
queue <int> q;
vector <int> v[NM];
int main()
{
    in>>n>>m>>s;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[a].push_back(b);
    }
    viz[s]=1;
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int i=0;i<v[fr].size();++i)
        {
            if(viz[v[fr][i]]==0)
            {
                viz[v[fr][i]]=1;
                dist[v[fr][i]]=dist[fr]+1;
                q.push(v[fr][i]);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(viz[i]==1)out<<dist[i]<<" ";
        else out<<"-1 ";
    }
    return 0;
}
