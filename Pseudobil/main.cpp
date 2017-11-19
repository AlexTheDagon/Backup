#include <iostream>
#include <fstream>
using namespace std;
ifstream in("pseudobil.in");
ofstream out("pseudobil.out");
int a[3005][3005],caz,k,d,n,m,x,y,x1,y1,x2,y2,x3,y3,x4,y4,p,t,n1,n2;
int main()
{
    in>>caz>>n>>k>>d;
    if(caz==1)out<<d*d/2-d+1;
    else
    {
        for(int i=1;i<=k;++i)
        {
            in>>x>>y;
            x1=n-y+x;
            y1=x+y-1;
            a[x1][y1]=1;
        }
        n1=2*n-1;
        t=n;
        p=0;
        for(int i=1;i<=n1;++i)
        {
            for(int j=t-p;j<=t+p;++j)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if(i<=n)++p;
            else --p;
        }
        ///bine
        in>>m;
        for(int i=1;i<=m;++i)
        {
            in>>x>>y;
            x1=n-y+x;
            y1=x+y-1;
            x2=n-(y+d/2)+x+d/2;
            y2=x+d/2+y+d/2-1;
            x3=n-y+x+d;
            y3=x+d+y-1;
            x4=n-(y-d/2)+x+d/2;
            y4=x+d/2+(y-d/2)-1;
            n2=a[x3][y3]-a[x2-1][y2]-a[x4][y4-1]+a[x1-1][y1-1];
            out<<n2<<'\n';
        }
    }
    return 0;
}
