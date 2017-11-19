#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("muzeu.in");
ofstream out("muzeu.out");
int n,a[251][251];
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
queue <pair <int,int>  > c;
int ii,jj;
pair <int,int> fr;
char x[251][251];
int inside(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=n)return 1;
    return 0;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            in>>x[i][j];
            if(x[i][j]=='#')a[i][j]=-2;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(x[i][j]=='P')
            {
                c.push(make_pair(i,j));
            }
        }
    }
    while(!c.empty())
    {
        fr=c.front();
        c.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(inside(ii,jj) && a[ii][jj]==0 && x[ii][jj]!='P')
            {
                a[ii][jj]=a[fr.x][fr.y]+1;
                c.push(make_pair(ii,jj));
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]==0 && x[i][j]!='P')out<<"-1"<<" ";
            else out<<a[i][j]<<" ";
        }
        out<<'\n';
    }
    return 0;
}
