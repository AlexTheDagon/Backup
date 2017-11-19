#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("insule.in");
ofstream out("insule.out");
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int n,m,a[101][101],viz[101][101];
pair <int,int> fr;
int ii,jj,R,G,B;
queue <pair<int,int> > c;
int inside(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=n)return 1;
    return 0;
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(viz[i][j]==0 && a[i][j]!=0)
            {
                R=0;
                G=0;
                B=0;
                while(!c.empty())
                {
                    fr=c.front();
                    c.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(inside(ii,jj) && a[ii][jj]==a[i][j] && viz[ii][jj]==0)
                        {

                            c.push(make_pair(ii,jj));
                        }
                    }
                }
            }
        }
    }
    return 0;
}
