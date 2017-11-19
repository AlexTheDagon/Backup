#include <iostream>
#include <fstream>
#define m 19997
using namespace std;
ifstream in("cifru.in");
ofstream out("cifru.out");
long long dp[2005],n,k;
long long gen(long long pas)
{
    long long t,rez=0;
    if(pas<=1 && pas<=k)return 1;
    if(dp[pas]!=0)return dp[pas];
    long long dd=1,p=1;
    for(long long d=2;d<=min(pas,k);++d)
    {
        if(k%d==0)
        {
            for(int i=pas-dd;i>=pas-d+1;--i)p=(p*i)%m;
            t=(p*gen(pas-d))%m;
            rez=(rez+t)%m;
            dd=d;
        }
    }
    dp[pas]=(gen(pas-1)+rez)%m;
    return dp[pas];
}
int main()
{
    in>>n>>k;
    out<<gen(n);
    return 0;
}
