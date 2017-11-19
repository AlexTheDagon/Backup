#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("alee.in");
ofstream out("alee.out");
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int n,m,x,y,a[176][176],fi,fj,p;
queue <pair <int,int>  > c;
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y;
        a[x][y]=-1;
    }
    in>>x>>y>>fi>>fj;
    a[x][y]=1;
    c.push(make_pair(x,y));
    while(!c.empty())
    {
        pair <int,int> fr=c.front();
        c.pop();
        int ii,jj;
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ii>0 && ii<=n && jj>0 && jj<=n && a[ii][jj]==0)
            {
                a[ii][jj]=a[fr.x][fr.y]+1;
                c.push(make_pair(ii,jj));
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    out<<a[fi][fj];
    return 0;
}
