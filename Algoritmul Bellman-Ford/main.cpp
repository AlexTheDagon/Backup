#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define NMAX 50005
#define MMAX 250005
#define inf (1<<30)
using namespace std;
ifstream in("bellmanford.in");
ofstream out("bellmanford.out");
vector <pair<int,int> > v[NMAX];
queue <int> q;
pair<int,int> fr;
bitset <NMAX> inq;
int ii,jj,nod,dist;
int a,b,act[NMAX],c,sem,n,m,dmin[NMAX];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)dmin[i]=inf;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        v[a].pb(mp(b,c));
    }
    sem=1;
    inq[1]=1;
    act[1]=1;
    dmin[1]=0;
    q.push(1);
    while(!q.empty() && sem)
    {
        nod=q.front();
        inq[nod]=0;
        q.pop();
        for(auto i:v[nod])
        {
            if(dmin[nod]+i.y<dmin[i.x])
            {
                if(inq[i.x])
                {
                    ++act[i.x];
                    if(act[i.x]==n)sem=0;
                }
                else
                {
                    q.push(i.x);
                    ++act[i.x];
                    inq[i.x]=1;
                }
                if(act[i.x]>n-1)sem=0;
                dmin[i.x]=dmin[nod]+i.y;
            }
        }
    }
    if(!sem)out<<"Ciclu negativ!";
    else
    {
        for(int i=2;i<=n;++i)out<<dmin[i]<<" ";
    }
    return 0;
}
