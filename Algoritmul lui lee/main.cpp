#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream in("lee.in");
ofstream out("lee.out");
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue <pair<int,int> > q;
pair<int,int> fr;
int ist,jst,ifin,jfin,n,m;
int cost[1005][1005];
bool viz[1005][1005];
int inside(int i,int j)
{
 return(i>0 && i<=n && j>0 && j<=m);
}
int main()
{
    in>>n>>m>>ist>>jst>>ifin>>jfin;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>cost[i][j];
    q.push(make_pair(ist,jst));
    viz[ist][jst]=1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<=3;++d)
        {
            int ii=fr.first+dx[d];
            int jj=fr.second+dy[d];
            if(inside(ii,jj) && viz[ii][jj]==0 && cost[ii][jj]!=-1)
            {
                q.push(make_pair(ii,jj));
                cost[ii][jj]=cost[fr.first][fr.second]+1;
                viz[ii][jj]=1;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            out<<cost[i][j]<<" ";
        }
        out<<'\n';
    }
    return 0;
}
