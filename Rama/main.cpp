#include <iostream>
#include <fstream>
#define Nmax 701
#define Mmax 701
using namespace std;
ifstream in("rama.in");
ofstream out("rama.out");
int n,m,sl[Nmax][Mmax],sc[Nmax][Mmax],i2,j2,i1,j1,maxx=0;
char r[Nmax][Mmax];
int main()
{in>>n>>m;
for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)in>>r[i][j];
for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)sl[i][j]=sl[i][j-1]+(r[i][j]-'0');
for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)sc[j][i]=sc[j-1][i]+(r[j][i]-'0');
for(i1=1;i1<=n;++i1)
{
    for(j1=1;j1<=m;++j1)
    {
        for(i2=i1;i2<=n;++i2)
        {
            for(j2=j1;j2<=m;++j2)
            {
                if((j2-j1+1)==(sl[i2][j2]-sl[i2][j1-1]) && (j2-j1+1)==sl[i1][j2]-sl[i1][j1-1] && (i2-i1+1)==(sc[i2][j1]-sc[i1-1][j1]) && (i2-i1+1)==(sc[i2][j2]-sc[i1-1][j2]))
                {
                    if((j2-j1+1)*(i2-i1+1)>maxx)maxx=(j2-j1+1)*(i2-i1+1);
                }
            }

        }
    }
}
out<<maxx;


    return 0;
}
