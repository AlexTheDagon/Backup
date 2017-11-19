#include <iostream>
using namespace std;
int n,m,sol=1000000000;
int main()
{
    cin>>n>>m;
    int dp[n+1][m+1],c[n+1];
    for(int i=1;i<=n;++i)
        cin>>c[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)dp[i][j]=1000000000;
    for(int i=1;i<=m;++i)
        for(int j=1;j<i;++j)
            dp[i][i-j]=min(dp[i][i-j],c[i]+c[j]);
    for(int i=m+1;i<=n;++i)
        for(int j=i-1;i-j<m;--j)
            for(int k=j-1;i-k<=m;--k)dp[i][i-j]=min(dp[i][i-j],dp[j][j-k]+c[i]);
    for(int i=n-m+2;i<=n;++i)
        for(int j=n-m+1;j<i;++j)sol=min(sol,dp[i][i-j]);
    cout<<sol<<endl;
    return 0;
}
///dp[i][j]--cant minima de vopsea pentru ca primele i sa respecte conditiile si ca ultiam bila vopsita sa fie i iar penultima j
