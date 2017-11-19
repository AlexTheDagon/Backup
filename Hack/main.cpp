#include <iostream>
#include <fstream>
using namespace std;
ofstream out("hack.out");
char a[55][55];
int n;
int main()
{
    out<<"50 50 1 1"<<'\n';
    n=50;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)a[i][j]='0';
    for(int i=1;i<=n;++i)
    {
        if(i%4==2)for(int j=1;j<n;++j)a[i][j]='1';
        if(i%4==0)for(int j=2;j<=n;++j)a[i][j]='1';
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)out<<a[i][j];
        out<<'\n';
    }
    return 0;
}
