#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lacusta.in");
ofstream out("lacusta.out");
int n,m,a[251][251],s[251],c2,c1,minn;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
        }
    }
    for(int i=2;i<=m;++i)
    {
        a[1][i]=a[1][i]+a[1][1];
        s[i]=1;
    }
    c1=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(j!=c1 && s[j]==1)
            {
                a[i][j]=a[i-1][j]+a[i][j];
                s[j]=2;
            }
        }
    }
    return 0;
}
