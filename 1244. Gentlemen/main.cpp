#include <iostream>

using namespace std;
int gr,n,g[105][100005],c[105],ind,sol[105],ii;
int main()
{
    cin>>gr>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<=n;++i)g[i][c[i]]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=100005;++j)
        {
            if(j>=c[i])g[i][j]+=g[i-1][j-c[i]];
            g[i][j]+=+g[i-1][j];
        }
    }
    if(g[n][gr]==0)cout<<"0";
    else
    {
        if(g[n][gr]>1)cout<<"-1";
        else
        {
            for(int i=n;i>0;--i)
            {
                if(g[i][gr]!=g[i-1][gr])
                {
                    gr-=c[i];
                }
                else sol[++ii]=i;
            }
            for(int i=ii;i>0;--i)cout<<sol[i]<<" ";
        }
    }
    return 0;
}
