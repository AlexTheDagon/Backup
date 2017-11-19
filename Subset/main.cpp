#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 1005
using namespace std;
ifstream in("subset.in");
ofstream out("subset.out");
long long n,a[NM],st,sol,cnt,p,m,dp[NM];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        dp[i]=1;
        for(int j=1;j<i;++j)
        {
            if(a[i]%a[j]==0)
            {
                dp[i]=max(dp[i],dp[j]+1);
                m=max(m,dp[i]);
            }
        }
    }
    out<<m;
    return 0;
}
