#include <iostream>
#include <queue>
#include <fstream>
#define x first
#define y second
#define NM 1005
#define pb push_back
#define mp make_pair
using namespace std;
ifstream in("taxa.in");
ofstream out("taxa.out");
queue <pair<int,int> > q[40005];
int n,m,is,js,ifin,jfin,minn=45000;
int fol[NM][NM];
int a[NM][NM];
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={-1,1,0,0,1,-1,1,-1};
int nr,ii,jj;
pair<int,int> fr;
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=m);
}
int main()
{
    in>>n>>m>>is>>js>>ifin>>jfin;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    q[0].push(mp(is,js));
    for(int i=0;i<=40001 && minn==45000;++i)
    {
        while(!q[i].empty() && minn==45000)
        {
            fr=q[i].front();
            q[i].pop();
            if(fr.x==ifin && fr.y==jfin)minn=min(minn,i);
            if(fol[fr.x][fr.y]==0)
            {
                fol[fr.x][fr.y]=1;
                for(int d=0;d<8;++d)
                {
                    ii=fr.x+dx[d];
                    jj=fr.y+dy[d];
                    if(ok(ii,jj) && fol[ii][jj]==0)
                    {
                        if(a[fr.x][fr.y]==a[ii][jj])
                        {
                            q[i].push(mp(ii,jj));
                        }
                        else
                        {
                            nr=0;
                            nr=a[fr.x][fr.y]*a[ii][jj];
                            q[i+nr].push(mp(ii,jj));
                        }
                    }
                }
            }
        }
    }
    out<<minn;
    return 0;
}
