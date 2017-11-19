#include <iostream>
#define NM 505
using namespace std;
long long n,dp[NM][NM],sum;
int main()
{
    cin>>n;
    dp[1][1]=1;
    dp[2][2]=1;
    dp[3][2]=1;
    dp[4][3]=1;
    for(int i=1;i<=n;++i)dp[i][i]=1;
    for(int i=5;i<=n;++i)///bine
    {
        for(int j=1;j<i;++j)
        {
            for(int k=1;k<j;++k)
            {
                dp[i][j]+=dp[i-j][k];
            }
        }
    }
    for(int i=1;i<=500;++i)sum+=dp[n][i];
    cout<<sum-1;
    return 0;
}
/**
dp[i][j]-->nr de scari din i caramizi cu ultima treapta de inaltime j
i=1->n;
dp[1][1]=1;
dp[3][2]=1;
dp[i][j]=dp[i-1][j-1]+dp[i-j][ceva<j],ceva=1->j;
**/
