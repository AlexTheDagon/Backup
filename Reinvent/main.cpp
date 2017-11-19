#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define NM 100005
using namespace std;
ifstream in("reinvent.in");
ofstream out("reinvent.out");
int dist[NM],viz[NM],n,m,a,b,x,dmin=1000000000,nod;
vector<int> v[NM];
queue<int> q;
int main()
{
    in>>n>>m>>x;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=x;++i)
    {
        in>>a;
        q.push(a);
        viz[a]=i;
    }
    while(dmin==1000000000)
    {
        nod=q.front();
        q.pop();
        for(auto i:v[nod])
        {
            if(viz[i]){if(viz[nod]!=viz[i])dmin=min(dist[i]+dist[nod]+1,dmin);}
            else
            {
                q.push(i);
                dist[i]=dist[nod]+1;
                viz[i]=viz[nod];
            }
        }
    }
    out<<dmin;
    return 0;
}
