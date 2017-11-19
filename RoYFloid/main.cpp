#include <iostream>
#include <fstream>
#define NM 1005
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int dmin[NM][NM],a,b,c,n;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)dmin[i][j]=1000000000;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b>>c;
        dmin[a][b]=c;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j)dmin[i][j]=min(dmin[i][j],dmin[i][k]+dmin[j][k]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)out<<i<<"->"<<j<<" : "<<dmin[i][j]<<'\n';
    return 0;
}
