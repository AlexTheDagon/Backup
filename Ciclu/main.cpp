#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define x first.first
#define y second.first
#define z second.second
#define f first
#define s second
#define mp make_pair
using namespace std;
ifstream in("ciclu.in");
ofstream out("ciclu.out");
int viz[1005],sol[1005];
queue<pair<int,int> > q;
vector<pair<int,pair<int,int> > > v[1005];
pair<int,pair<int,int> > fr;
int n,m,a,b,c;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)sol[i]=1000000000;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        v[a].pb(mp(b,c));
    }
    for(int act=1;act<=n;++act)
    {
        for(int i=1;i<=n;++i)viz[i]=0;
        q.push(mp(act,0));
        while(!q.empty())
        {
            fr=q.front();
            q.pop();
            for(auto i:v[fr.y])
            {
                q.push(mp(i.x,fr.y+i.y))
            }
        }
    }
    return 0;
}
