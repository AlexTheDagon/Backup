#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lacusta.in");
ofstream out("lacusta.out");
int n,m,a[3][251],b[3][255],k=1,min1=100000000,c,min2,ult;
int main()
{
    in>>n>>m;
    for(int i=1;i<=2;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int j=2;j<=m;++j)
    {
        b[2][j]=a[1][j]+a[2][j]+a[1][1];
        min1=min(min1,b[2][j]);
    }
    b[2][1]=min1+a[2][1];
    for(int k=3;k<=n;++k)
    {
        for(int i=1;i<=m;++i)
        {
            a[1][i]=a[2][i];
            in>>a[2][i];
            b[1][i]=b[2][i];
        }
        if(k==n)ult=a[2][m];
        min1=100000000;
        for(int j=1;j<=m;++j)
        {
            if(min1>=b[1][j])
            {
                min2=min1;
                min1=b[1][j];
                c=j;
            }
            else
            {
                if(min2>=b[1][j])min2=b[1][j];
            }
        }
        for(int j=1;j<=m;++j)
        {
            if(j!=c)b[2][j]=a[2][j]+a[1][j]+min1;
            else b[2][j]=a[2][j]+a[1][j]+min2;
        }
    }
    min1=100000000;
    for(int j=1;j<=m-1;++j)
    {
        min1=min(min1,b[2][j]);
    }
    out<<ult+min1;
    return 0;
}
