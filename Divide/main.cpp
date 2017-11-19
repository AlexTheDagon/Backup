#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define NM 100005
#define PM 32
using namespace std;
ifstream in("divide.in");
ofstream out("divide.out");
int n,x,c,dp[PM][NM],a[NM],sp[NM],sum;
int main()
{
    in>>n>>x>>c;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=1;i<=n;++i)dp[1][i]=abs(dp[1][i-1]+a[i]);
    for(int i=1;i<=n;++i)dp[1][i]=abs(dp[1][i]-c);
    for(int i=n;i>0;--i)sp[i]=sp[i+1]+a[i];///bine
    for(int i=2;i<=x;++i)
        for(int j=1;j<=n;++j)dp[i][j]=(1<<30);
    for(int i=2;i<=x;++i)
    {

        sum+=dp[i][n];
    }
    sum+=dp[1][n];
    out<<sum;
    return 0;
}
/**
dp[i][j]---cost mx pt secventa care are subsecventa i terminata pe pozitia j



**/
