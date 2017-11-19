#include <iostream>
#include <fstream>
#define NM 1025
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");\
int a[NM],b[NM],c[NM][NM],n,m,k,LCS[NM];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
    }
    for(int i=1;i<=m;++i)
    {
        in>>b[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
    }
    out<<c[n][m]<<'\n';
    while(n)
    {
        if (a[n]==b[m])
        {
            LCS[++k] = a[n];
            --n;
            --m;
        }
        else
        {
            if(c[n-1][m] < c[n][m-1])--m;
            else --n;
        }
    }
    for(int i=k;i>0;--i)
    {
        out<<LCS[i]<<" ";
    }
    return 0;
}
