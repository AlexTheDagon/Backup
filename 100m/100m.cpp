#include <iostream>
#include <fstream>
#define NM 5005
#define modulo 666013
using namespace std;
ifstream in("100m.in");
ofstream out("100m.out");
long long n,dp[3][NM],s;
int main()
{
    in>>n;
    dp[1][1]=1;
    s=1;
    for(int i=2;i<=n;++i)
    {
        dp[2][i]=s;
        for(int j=i-1;j>0;--j)
        {
            dp[2][j]=dp[2][j+1]+dp[1][j];
            dp[2][j]%=modulo;
        }
        s=0;
        for(int j=i;j>0;--j)
        {
            s+=dp[2][j];
            dp[1][j]=dp[2][j];
            dp[2][j]=0;
        }
        s%=modulo;
    }
    out<<s;
    return 0;
}
