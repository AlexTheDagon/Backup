#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("taxe2.in");
ofstream out("taxe2.out");
int c[101][101],dp[101][101],n,s,ii,jj;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
queue <pair <int,int> > q;
pair <int,int> fr;
int inside(int f,int g)
{
    if(f>0 && f<=n && g>0 && g<=n)return 1;
    return 0;
}
int main()
{
    in>>s>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            in>>c[i][j];
            dp[i][j]=4000000;
        }
    }
    dp[1][1]=c[1][1];
    q.push(make_pair(1,1));
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(inside(ii,jj) && dp[ii][jj]>dp[fr.x][fr.y]+c[ii][jj])
            {
                dp[ii][jj]=dp[fr.x][fr.y]+c[ii][jj];
                q.push({ii,jj});
            }
        }
    }
    if(dp[n][n]>s)out<<"-1";
    else out<<s-dp[n][n];
    return 0;
}
