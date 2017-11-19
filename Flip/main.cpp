#include <iostream>
#include <fstream>
using namespace std;
ifstream in("flip.in");
ofstream out("flip.out");
int n,m,a[20][20],sp[20],nr=1,spx[20],smax,sum;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            sp[i]+=a[i][j];
        }
    }
    for(int sb=0;sb<(1<<m);++sb)
    {
        sum=0;
        for(int i=1;i<=n;++i)spx[i]=sp[i];
        for(int j=0;j<m;++j)
        {
            if(sb&(1<<j))
            {
                for(int i=1;i<=n;++i)
                {
                    spx[i]=spx[i]-2*a[i][m-j];
                }
            }
        }
        for(int i=1;i<=n;++i)sum+=max(spx[i],-spx[i]);
        smax=max(smax,sum);
    }
    out<<smax;
    return 0;
}
