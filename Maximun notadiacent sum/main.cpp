#include <iostream>

using namespace std;
int a[1005],dp[1005],maxx=-(1<<29),n;
int main()
{
    cin>>n;
    n+=2;
    for(int i=3;i<=n;++i)cin>>a[i];
    for(int i=3;i<=n;++i)
    {
        dp[i]=max(dp[i-2],dp[i-3]);
        if(dp[i]<0)dp[i]=0;
        dp[i]+=a[i];
    }
    for(int i=3;i<=n;++i)maxx=max(dp[i],maxx);
    cout<<maxx;
    return 0;
}
