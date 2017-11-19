#include <iostream>

using namespace std;
long long a[105][505],n,m,dp[105][505],minn,inddd,v[105][505],sol[100000],k,ii,jj,s;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)cin>>a[i][j];
    for(int i=1;i<=m;++i)dp[1][i]=a[1][i];
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dp[i][j]=dp[i-1][j]+a[i][j];
            v[i][j]=-1;
        }
        for(int ind=1;ind<=m;++ind)
        {
            s=0;
            for(int j=ind-1;j>0;--j)
            {
                s+=a[i][j];
                if(dp[i][j]>dp[i][ind]+s)
                {
                    dp[i][j]=dp[i][ind]+s;
                    v[i][j]=ind;
                }
            }
            s=0;
            for(int j=ind+1;j<=m;++j)
            {
                s+=a[i][j];
                if(dp[i][j]>dp[i][ind]+s)
                {
                    dp[i][j]=dp[i][ind]+s;
                    v[i][j]=ind;
                }
            }
        }

    }
    minn=1000000000000000;
    for(int i=1;i<=m;++i)
    {
        if(dp[n][i]<minn)
        {
            jj=i;
            minn=dp[n][i];
        }
    }
    ii=n;
    while(ii>1)
    {
        if(v[ii][jj]==-1)
        {
            --ii;
            sol[++k]=jj;
        }
        else
        {
            if(v[ii][jj]<jj)
            {
                inddd=v[ii][jj];
                for(int i=jj;i>inddd;--i)sol[++k]=i;
                jj=inddd;
            }
            else
            {
                inddd=v[ii][jj];
                for(int i=jj;i<inddd;++i)sol[++k]=i;
                jj=inddd;
            }
        }
    }
    cout<<jj<<" ";
    for(int i=k;i>0;--i)cout<<sol[i]<<" ";
    return 0;
}
