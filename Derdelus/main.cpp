#include <iostream>
#include <fstream>
#define NM 1005
#define md 666013
using namespace std;
ifstream in("derdelus.in");
ofstream out("derdelus.out");
int n,m,r,c,a[NM][NM],p,s,sc[NM][NM],sd[NM][NM];
int main()
{
    in>>n>>m>>p;
    for(int i=1;i<=p;++i)
    {
        in>>r>>c;
        a[r][c]=-1;
    }
    a[1][1]=1;
    sc[1][1]=1;
    sd[1][1]=1;
    ///bine
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            s=0;
            if(a[i][j]!=-1)
            {
                if(i>m)s=sc[i-1][j]-sc[i-m-1][j];
                else s=sc[i-1][j];///bine(vin de deasupra)
                if(j>m)s+=sd[i-1][j-1]-sd[i-m-1][j-m-1];
                else s+=sd[i-1][j-1];
                s=(s+3*md)%md;
                a[i][j]=s;
            }
            else a[i][j]=0;
            sd[i][j]=(sd[i-1][j-1]+a[i][j])%md;
            sc[i][j]=(sc[i-1][j]+a[i][j])%md;
        }
    }
    for(int i=1;i<=n;++i)out<<a[n][i]<<" ";
    ///de verif modulele
    return 0;
}
