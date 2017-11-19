#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sotron.in");
ofstream out("sotron.out");
int a[300][300];
int viz[300][300],cul[300][300],n;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int rec(int i,int j)
{
    if(viz[i][j]==1)return a[i][j];
    viz[i][j]=1;
    if(cul[i][j]==1)a[i][j]=max(a[i][j],a[i][j]+rec(i-1,j));
    else a[i][j]=max(a[i][j],a[i][j]+rec(i,j+1));
    return a[i][j];
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
            if((i+j)%2==0)cul[i][j]=1;
        }
    }
    for(int i=1;i<=n;++i)viz[0][i]=viz[i][n+1]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)rec(i,j);
    int maxx=-1000;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=n;++j)maxx=max(maxx,a[i][j]);
    out<<maxx;
    return 0;
}
