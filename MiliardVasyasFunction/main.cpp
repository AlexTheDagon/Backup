#include <iostream>

using namespace std;
int dp[15][90],s;
int main()
{
    cin>>s;
    if(s==1)cout<<"10";
    else
    {
        for(int i=0;i<=9;++i)dp[1][i]=1;
        for(int i=2;i<=9;++i)
        {
            for(int j=0;j<=81;++j)
            {
                for(int d=0;d<=9;++d)
                {
                    if(j-d>=0)dp[i][j]+=dp[i-1][j-d];
                }
            }
        }
        cout<<dp[9][s];
    }
    return 0;
}
