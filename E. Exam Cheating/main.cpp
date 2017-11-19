#include <iostream>
#include <bitset>
using namespace std;
int n,p,k,m,x,maxx;
bitset<1005> a[1005],b[1005],dp[1005][55],sol,s;
int main()
{
    cin>>n>>p>>k;
    cin>>m;
    for(int j=1;j<=m;++j)
    {
        cin>>x;
        a[x+k-1]=1;
    }
    cin>>m;
    for(int j=1;j<=m;++j)
    {
        cin>>x;
        b[x+k-1]=1;
    }
    for(int i=k+1;i<=n;++i)
    {
        a[i]=a[i]^a[i-k-1]|a[i-1];
        b[i]=b[i]^b[i-k-1]|b[i-1];
    }
    for(int q=1;q<=p;++q)
    {
        for(int i=1;i<=n;++i)
        {
            maxx=0;
            for(int j=1;j<i;++j)
            {
                s=dp[j][q-1]|a[j];
                if(s.count()>maxx)
                {
                    maxx=s.count();
                    sol=s;
                }
               s=dp[j][q-1]|b[j];
                if(s.count()>maxx)
                {
                    maxx=s.count();
                    sol=s;
                }
            }
            dp[i][q]=sol;
        }
    }
    maxx=0;
    for(int q=1;q<=p;++q)
        for(int i=1;i<=n;++i)maxx=max(maxx,dp[i][q].count());
    return 0;
}
