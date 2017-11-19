#include <iostream>
#include <fstream>
using namespace std;
ifstream in("spider.in");
ofstream out("spider.out");
int n,m,a[1005][1005],viz[1005][1005],dp[1005][1005],d,is,js,maxx=0,pas;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m);
}
int dfs(int i,int j)
{
    viz[i][j]=pas;
    int ii,jj,maxx=0,sem=0;
    for(d=0;d<4;++d)
    {
        ii=i+dx[d];
        jj=j+dy[d];
        if(a[ii][jj]>maxx && a[ii][jj]<=a[i][j] && ok(ii,jj) && viz[ii][jj]!=pas)
        {
            sem=1;
            maxx=a[ii][jj];
            is=ii;
            js=jj;
        }
    }
    if(sem)dp[i][j]=1+dfs(is,js);
    else dp[i][j]=1;
    return dp[i][j];
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!viz[i][j])
            {
                ++pas;
                dfs(i,j);
            }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            out<<dp[i][j]<<" ";
        }
        out<<'\n';
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(dp[i][j]>maxx)
            {
                maxx=dp[i][j];
                is=i;
                js=j;
            }
    out<<maxx<<'\n';
    return 0;
}
