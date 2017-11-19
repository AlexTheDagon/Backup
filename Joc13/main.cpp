#include <iostream>
#include <fstream>
using namespace std;
ifstream in("joc13.in");
ofstream out("joc13.out");
int a[2][5001],n,k,dp[2][5001],s0,s1,m0,m1;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)in>>a[0][i];
    for(int i=1;i<=n;++i)in>>a[1][i];
    dp[0][1]=a[0][1];
    dp[1][1]=a[0][1]+a[1][1];
    for(int i=2;i<=n;++i)
    {
        s0=0;
        s1=0;
        m0=a[0][i]+dp[0][i-1];
        m1=a[1][i]+dp[1][i-1];
        for(int j=i;j>i-k+1 && j>1;--j)
        {
            s0+=a[0][j];
            m0=max(m0,dp[0][j-1]+s0);
            s1+=a[1][j];
            m1=max(m1,dp[1][j-1]+s1);
        }
        dp[0][i]=a[0][i]+m1;
        dp[1][i]=a[1][i]+m0;
    }
    out<<max(dp[1][n],dp[0][n]-a[0][n]);
    return 0;
}
/// dp[0][i]-de la j pana la i venind de jos
/// dp[1][i]-de la j pana la i venind de pe linie

///IDEEA 2:
///fac parcgere pe fiecare linie si dupa maxim k
///elemente se schimba coloana
///Ultimul caz tb facut verificare
