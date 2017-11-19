#include <iostream>
#include <fstream>
using namespace std;
ifstream in("culori3.in");
ofstream out("culori3.out");
long long dp[5001][7],n,s;
int main()
{
    in>>n;
    for(int i=1;i<=5;++i)dp[1][i]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=5;++j)dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
    }
    for(int i=1;i<=5;++i)s+=dp[n][i];
    out<<s;
    return 0;
}

