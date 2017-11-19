#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lacusta.in");
ofstream out("lacusta.out");
int a[251][251],m,n,minn=1000000,c1,c2,s[251],minn2;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)in>>a[i][j];
    }
    for(int i=2;i<=n;++i)
    {
        a[1][i]=a[1][i]+a[1][1];
    }
    c1=1;
    for(int i=2;i<=n;++i)
    {
        minn=1000000;
        for(int j=1;j<=m;++j)
        {
            if(j!=c1 && s[j]==1)
            {
                a[i][j]=a[i-1][j]+a[i][j];
                s[j]=2;
            }
        }
        for(int j=1;j<=m;++j)
        {
            if(j!=c1)
            {
                if(minn>a[i][j])
                {
                    minn=a[i][j];
                    c2=j;
                }
            }
        }
        a[i][c1]=minn+a[i][c1];
        s[c1]=2;
        for(int j=1;j<=m;++j)
        {
            if(j!=c2)
            {
                a[i][j]=min(a[i][j],minn+a[i][j]-a[i-1][j]);
            }
        }
        c1=c2;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)cout<<a[i][j]<<" ";
        cout<<endl;
    }
    out<<a[n][m];
    return 0;
}
