#include <iostream>
#include <fstream>
using namespace std;
ifstream in("tort2.in");
ofstream out("tort2.out");
int n,m,k,lat,lng,a[505][505],minn,tot,moduri;
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
        }
    }
    minn=10000000;
    tot=a[n][m];
    lat=m-k;
    lng=n;
    while(lat<=m)
    {
        for(int i=0;i<=n-lng;++i)
        {
            for(int j=0;j<=m-lat;++j)
            {
                if(a[i+lng][j+lat]-a[i][j+lat]-a[i+lng][j]+a[i][j]<minn)
                {
                    moduri=0;
                    minn=a[i+lng][j+lat]-a[i][j+lat]-a[i+lng][j]+a[i][j];
                }
                if(a[i+lng][j+lat]-a[i][j+lat]-a[i+lng][j]+a[i][j]==minn)++moduri;
            }
        }
        ++lat;
        --lng;
    }
    out<<tot-minn<<'\n'<<moduri;
    return 0;
}
