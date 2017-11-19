#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cstdlib>
using namespace std;
ifstream in("profit.in");
ofstream out("profit.out");
int n,a[2005],b[2005];
int cmin[3][2005],minn,minc[3][2005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=1;i<=n;++i)b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cmin[2][j]=minc[1][j]+abs(a[i]-b[j]);
            if(j>1)minc[2][j]=min(minc[2][j-1],cmin[2][j]);
            else minc[2][j]=cmin[2][j];
        }
        for(int j=1;j<=n;++j)
        {
            minc[1][j]=minc[2][j];
            cmin[1][j]=cmin[2][j];
        }
    }
    minn=1<<30;
    for(int i=1;i<=n;++i)minn=min(minn,cmin[1][i]);
    sort(b+1,b+n+1,greater<int>());
    for(int i=1;i<=n;++i)cmin[1][i]=cmin[2][i]=minc[1][i]=minc[2][i]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cmin[2][j]=minc[1][j]+abs(a[i]-b[j]);
            if(j>1)minc[2][j]=min(minc[2][j-1],cmin[2][j]);
            else minc[2][j]=cmin[2][j];
        }
        for(int j=1;j<=n;++j)
        {
            minc[1][j]=minc[2][j];
            cmin[1][j]=cmin[2][j];
        }
    }
    for(int i=1;i<=n;++i)minn=min(minn,cmin[1][i]);
    out<<minn;

    return 0;
}
