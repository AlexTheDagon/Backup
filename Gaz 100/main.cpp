#include <iostream>
#include <fstream>
using namespace std;
ifstream in("gaz.in");
ofstream out("gaz.out");
long long dp[2005],l,c,p,n,g[2005],d,ext,sum,cant;
int main()
{
    in>>l>>p>>d>>c>>n;
    for(int i=1;i<=n;++i)
    {
        in>>g[i];
        cant+=g[i];
        dp[i]=1000000000000000;
    }
    for(int i=1;i<=n;++i)
    {
        sum=g[i];
        ext=0;
        for(int j=i-1;j>=0;--j)
        {
            dp[i]=min(dp[i],dp[j]+ext*c+p);
            sum+=g[j];
            ext+=max(0LL,sum-g[j]-l);
        }
    }
    out<<dp[n]+cant*d;
    return 0;
}
