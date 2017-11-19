#include <iostream>
#include <fstream>
using namespace std;
ifstream in("unuzero.in");
ofstream out("unuzero.out");
int dp[2][1000005],sp[1000005],n,p,q;
int main()
{
    in>>n>>p>>q;
    dp[0][0]=1;
    sp[0]=1;
    for(int i=1;i<=n;++i)
    {
        dp[0][i]=(dp[0][i-1]+dp[1][i-1])%666013;
        sp[i]=sp[i-1]+dp[0][i];
        sp[i]%=666013;
        if(i-p>=0)dp[1][i]=sp[i-p];
        if(i-q-1>=0)dp[1][i]-=sp[i-q-1];
        dp[1][i]=(dp[1][i]+666013)%666013;
    }
    out<<(dp[0][n]+dp[1][n]-1)%666013;
    return 0;
}
///dp[i]---nr de siruri de lungime i care se termina in 0
