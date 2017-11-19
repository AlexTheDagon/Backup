#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lacusta.in");
ofstream out("lacusta.out");
unsigned int n,m,b[251][251],k=1,min1=100000000,c,min2;
unsigned char a[251][251];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int j=2;j<=m;++j)b[1][j]=a[1][j]+a[1][1]-'0'-'0';
    b[1][1]=a[1][1]-'0';
    for(int j=2;j<=m;++j)
    {
        b[2][j]=a[1][j]+a[2][j]+a[1][1]-'0'-'0'-'0';
        min1=min(min1,b[2][j]);
    }
    b[2][1]=min1+a[2][1]-'0';
    for(int i=3;i<=n;++i)
    {
        min1=100000000;
        for(int j=1;j<=m;++j)
        {
            if(min1>=b[i-1][j])
            {
                min2=min1;
                min1=b[i-1][j];
                c=j;
            }
            else
            {
                if(min2>=b[i-1][j])min2=b[i-1][j];
            }
        }
        for(int j=1;j<=m;++j)
        {
            if(j!=c)b[i][j]=a[i][j]+a[i-1][j]+min1-'0'-'0';
            else b[i][j]=a[i][j]+a[i-1][j]+min2-'0'-'0';
        }
    }
    min1=100000000;
    for(int j=1;j<=m-1;++j)
    {
        min1=min(min1,b[n][j]);
    }
    out<<a[n][m]+min1-'0';
    return 0;
}
