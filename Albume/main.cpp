#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream in("albume.in");
ofstream out("albume.out");
int c,k,q;
double dp[1005][1005],p1,p2,prob;
int main()
{
    in>>c>>k>>q;
    dp[1][1]=1.0;
    for(int i=1;i<q;++i)
    {
        for(int j=1;j<=c;++j)
        {
            p2=double(c-j)*k/(c*k-i);
            p1=double(j*k-i)/(c*k-i);
            dp[i+1][j]+=(dp[i][j]*p1);
            dp[i+1][j+1]+=(dp[i][j]*p2);
        }
    }
    for(int i=1;i<=c;++i)
    {
        prob+=(double)(i*dp[q][i]);
    }
    out<<fixed<<setprecision(9)<<prob;
    return 0;
}
