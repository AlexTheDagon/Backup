#include <iostream>
#include <math.h>
using namespace std;
int dp[60001],n,minn;
int main()
{
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    for (int i=3;i<=n;++i)
    {
        minn=dp[i-1]+1;
        for (int j=2;j<=sqrt(i);++j)minn=min(minn,dp[i-j*j]+1);
        dp[i]=minn;
    }
    cout<<dp[n];
    return 0;
}
