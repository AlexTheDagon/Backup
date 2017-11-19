#include <iostream>
#include <fstream>
using namespace std;
ifstream in("caibicol.in");
ofstream out("caibicol.out");
int n,k,x,cst[501][501],w[501],b[501],minn;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>x;
        if(x==1)b[i]=1;
        else w[i]=1;
    }
    for(int i=1;i<=n;++i)
    {
        w[i]=w[i]+w[i-1];
        b[i]=b[i]+b[i-1];
    }
    for(int j=1;j<=n;++j)cst[1][j]=w[j]*b[j];
    for(int i=2;i<=k;++i)
    {
        for(int j=i;j<=n;++j)
        {
            minn=1000000000;
            for(int jj=i-1;jj<j;++jj)///verificat
            {
                minn=min(cst[i-1][jj]+(w[j]-w[jj])*(b[j]-b[jj]),minn);///verificat
            }
            cst[i][j]=minn;
        }
    }
    out<<cst[k][n];
    return 0;
}
