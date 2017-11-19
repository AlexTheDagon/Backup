#include <iostream>
#include <fstream>
using namespace std;
ifstream in("triunghi3.in");
ofstream out("triunghi3.out");
int a[1005][1005],dp[1005][1005],n,sd[1005][1005],sc[1005][1005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)in>>a[i][j];
    }
    ///bine
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            sd[i][j]=sd[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            sc[i][j]=sc[i-1][j]+a[i][j];
        }
    }
    ///ar tb sa fie bine
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i][j]=2000000000;
            if(j!=1)dp[i][j]=dp[i-1][j-1]+(sc[n][j]-sc[i-1][j]+sc[n-1][j-1]-sc[i-2][j-1])*(n-i+1)+sc[n][j-1]-sc[i-2][j-1]+sc[n-1][j-1]-sc[i-1][j-1];
            if(i!=j)dp[i][j]=min(dp[i][j],dp[i-1][j]+(sd[n][j+n-i]-sd[i-1][j-1]+sd[n-1][j+n-i]-sd[i-2][j-1])*(n-i+1)+sd[n][j+n-i+1]-sd[i-2][j-1]+sd[n-1][j+n-i]-sd[i-1][j]);
        }
    }
    int smax=2000000000;
    for(int i=1;i<=n;++i)
    {
        smax=min(smax,dp[n][i]);
    }
    out<<smax;
    return 0;
}
