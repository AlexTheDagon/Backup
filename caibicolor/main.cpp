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
    ///Bine
    for(int j=1;j<=n;++j)cst[1][j]=w[j]*b[j];
    for(int j=2;j<=k;++j)
    {
        for(int i=j;i<=n;++i)
        {
            minn=1000000000;
            for(int ii=j-1;ii<i;++ii)///verificat
            {
                minn=min(cst[j-1][ii]+(w[i]-w[ii])*(b[i]-b[ii]),minn);///verificat
            }
            cst[j][i]=minn;
        }
    }
    out<<cst[k][n];
    return 0;
}
