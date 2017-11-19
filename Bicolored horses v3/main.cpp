#include <iostream>

using namespace std;
int dp[505][505],n,k,b[505],w[505],c,minn;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>c;
        w[i]=w[i-1];
        b[i]=b[i-1];
        if(c)++w[i];
        else ++b[i];
    }
    for(int i=1;i<=n;++i)dp[1][i]=w[i]*b[i];
    for(int i=2;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            minn=1<<29;
            for(int k=1;k<=j;++k)
            {
                minn=min(minn,dp[i-1][k]+(w[j]-w[k])*(b[j]-b[k]));
            }
            dp[i][j]=minn;
        }
    }
    cout<<endl<<endl;
    for(int i=1;i<=n;++i)cout<<w[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;++i)cout<<b[i]<<" ";
    cout<<endl<<endl;
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n;++j)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[k][n];
    return 0;
}
