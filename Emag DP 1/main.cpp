#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int dp[105][105],n;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)in>>dp[i][j];
    }
    for(int i=n-1;i>0;--i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    out<<dp[1][1]<<'\n';
    out<<"1 1"<<'\n';
    for(int i=1;i<=n;++i)
    {

    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)out<<dp[i][j]<<" ";
        out<<'\n';
    }
    return 0;
}
