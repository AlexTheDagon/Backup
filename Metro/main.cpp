#include <iostream>
#include <iomanip>
using namespace std;
double cmin[1001][1001];
int x,y,s[1001][1001],n,k,m;
int main()
{
    cin>>n>>m;
    cin>>k;
    for(int i=0;i<k;++i)
    {
        cin>>x>>y;
        s[x][y]=1;
    }
    for(int i=1;i<=m;++i)cmin[0][i]=cmin[0][i-1]+100;
    for(int i=1;i<=n;++i)cmin[i][0]=cmin[i-1][0]+100;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cmin[i][j]=100+min(cmin[i-1][j],cmin[i][j-1]);
            if(s[i][j]==1)cmin[i][j]=min(cmin[i][j],cmin[i-1][j-1]+141.421356);
        }
    }
    cout<<fixed<<setprecision(0)<<cmin[n][m];
    return 0;
}
