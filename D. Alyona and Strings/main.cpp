#include <iostream>
#define NM 1005
using namespace std;
int n,m,kk,dp[NM][NM][12][2];
string s,t;
int main()
{
    cin>>n>>m>>kk;
    cin>>s>>t;
    s='#'+s;
    t='*'+t;
    for(int k=1;k<=kk;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                dp[i][j][k][0]=max(dp[i][j-1][k][0],dp[i-1][j][k][0]);
                if(s[i]==t[j])
                {
                    dp[i][j][k][1]=max(dp[i-1][j-1][k][1]+1,dp[i-1][j-1][k-1][0]+1);
                }
                dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j][k][1]);
            }
        }
    }
    cout<<dp[n][m][kk][0];
    return 0;
}
