#include <iostream>
#include <fstream>
using namespace std;
ifstream in("energii.in");
ofstream out("energii.out");
int g,w,a[1001][5001],sol,e[1001],c[1001],s;
int main()
{
    in>>g>>w;
    for(int i=1;i<=g;++i)
    {
        in>>e[i]>>c[i];
        s=s+e[i];
    }
    if(s<w)out<<"-1";
    else
    {
        for(int i=0; i<=w; i++)a[0][i]=200000000;
        for(int i=1;i<=g;++i)
        {
            for(int j=1;j<=w;++j)
            {
                if(j<e[i])
                {
                    a[i][j]=min(a[i-1][j],c[i]);
                }
                else
                {
                    a[i][j]=min(a[i-1][j],a[i-1][j-e[i]]+c[i]);
                }
            }
        }
        out<<a[g][w];
    }
    return 0;
}
