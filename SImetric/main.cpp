#include <iostream>
#include <fstream>
using namespace std;
ifstream in("simetric.in");
ofstream out("simetric.out");
int a[405][405],k,dp[405][405],n,m,sol[500];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int i=n;i>0;--i)
    {
        for(int j=m;j>0;--j)
        {
            k=0;
            while(a[i+k][j]==a[i][j+k] && i+k<=n && j+k<=m)++k;
            dp[i][j]=min(dp[i+1][j+1]+1,k);
            ++sol[1];
            --sol[dp[i][j]+1];
        }
    }
    for(int i=1;i<=450;++i)sol[i]+=sol[i-1];
    for(int i=1;sol[i]!=0;++i)out<<sol[i]<<'\n';
    return 0;
}
