#include <iostream>
#include <fstream>
using namespace std;
ifstream in("acces.in");
ofstream out("acces.out");
int a[1005][1005],b[1005][1005];
int q,n,m,x,y,t,ii,jj;

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            a[i][j]=1-a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==0 && a[i-1][j] && a[i][j-1])
            {
                ii=i;
                jj=j;
                while(a[ii][jj]==0 && jj<=m)++jj;
                while(a[ii][jj-1]==0 && ii<=n)++ii;
                b[ii][jj]=a[i-1][j-1];
            }
            else if(a[i][j]==1)a[i][j]=a[i-1][j]+a[i][j-1]-b[i][j]+1;
            if(a[i-1][j] && a[i][j-1] && a[i][j])a[i][j]-=a[i-1][j-1];
        }
    }
    in>>t;
    for(int i=1;i<=t;++i)
    {
        in>>x>>y;
        out<<a[x][y]<<'\n';
    }
    return 0;
}
