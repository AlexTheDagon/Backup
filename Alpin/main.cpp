#include <iostream>
#include <fstream>
using namespace std;
ifstream in("alpin.in");
ofstream out("alpin.out");
int dp[1030][1030],a[1030][1030],n,FatherI[1030][1030],FatherJ[1030][1030],lmax,si,sj;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
int ok(int i,int j)///bine
{
    if(i>0 && i<=n && j>0 && j<=n)return 1;
    return 0;
}
int DFS(int i,int j)///bine
{
    if(!ok(i,j))return 0;
    if(dp[i][j])return dp[i][j];
    for(int dir=0;dir<4;++dir)
    {
        int ii=i+dx[dir];
        int jj=j+dy[dir];
        {
            if(a[ii][jj]>a[i][j])
            {
                int D=DFS(ii,jj);
                if(D>dp[i][j])
                {
                    dp[i][j]=D;
                    FatherI[i][j]=ii;
                    FatherJ[i][j]=jj;
                }
            }
        }
    }
    dp[i][j]++;
    return dp[i][j];
}
void path(int i,int j)///bine
{
    out<<i<<" "<<j<<'\n';
    if(ok(FatherI[i][j],FatherJ[i][j]))path(FatherI[i][j],FatherJ[i][j]);
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>a[i][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int D=DFS(i,j);
            if(D>lmax)

            {
                lmax=D;
                si=i;
                sj=j;
            }
        }
    }
    out<<lmax<<'\n';
    path(si,sj);
    return 0;
}
