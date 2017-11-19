#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("tsunami.in");
ofstream out("tsunami.out");
int a[1001][1001],viz[1001][1001],zone,n,m,H;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
queue <pair <int,int>  > c;
pair <int,int> fr;
int ii,jj;
int inside(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=m)return 1;
    return 0;
}
int main()
{
    in>>n>>m>>H;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==0 && viz[i][j]==0)
            {
                c.push(make_pair(i,j));
                while(!c.empty())
                {
                    fr=c.front();
                    c.pop();
                    if(a[fr.x][fr.y]!=0)
                    {
                        ++zone;
                    }
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(inside(ii,jj) && a[ii][jj]<H && viz[ii][jj]==0)
                        {
                            c.push(make_pair(ii,jj));
                            viz[ii][jj]=1;
                        }
                    }
                }
            }
        }
    }
    out<<zone;
    return 0;
}
