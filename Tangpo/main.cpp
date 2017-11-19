#include <iostream>
#include <fstream>
#define m 999983
using namespace std;
ifstream in("tango.in");
ofstream out("tango.out");
long long dp[10],a[100005],k,n;
long long sol,aux;
int lgput(long long b,long long e)
{
    if(e==1)return b;
    if(e%2==0)return lgput((b*b)%m,e/2)%m;
    return (lgput((b*b)%m,e/2)%m*b)%m;
}
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)in>>a[i];
    dp[0]=1;
    for(int i=1;i<=8;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[j]<=i)
            {
                dp[i]+=dp[i-a[j]];
                dp[i]%=m;
            }
        }
    }
    sol=dp[8];
    out<<lgput(sol,k/8);
    return 0;
}
