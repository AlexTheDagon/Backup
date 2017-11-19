#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sg1.in");
ofstream out("sg1.out");
int n,k,d1,d2;
int dp[120][120][100];
void add(int l1,int c1,int l2,int c2)
{
    int ii=1,t=0;
    for(ii=1;ii<=dp[l1][c1][0] || ii<=dp[l2][c2][0] || t;++ii)
    {
        dp[l2][c2][ii]=((t+=dp[l1][c1][ii]+dp[l2][c2][ii])%10);
        t/=10;
    }
    --ii;
    dp[l2][c2][0]=ii;
}
int main()
{
    in>>n>>k>>d1>>d2;
    if(k+(k-1)*d1<=n)
    {
        for(int i=1;i<=n-k+(k-1)*d1+1;++i)
        {
            dp[i][1][1]=1;
            dp[i][1][0]=1;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<k;++j)
            {
                for(int l=d1+1;l<=d2+1;++l)
                {
                    if(i+l<=n)
                    {
                        add(i,j,i+l,j+1);
                    }
                }
            }
        }
        for(int i=k+(k-1)*d1;i<n;++i)add(i,k,n,k);
        for(int i=dp[n][k][0];i>0;--i)out<<dp[n][k][i];
    }
    else out<<"0";
    return 0;
}
