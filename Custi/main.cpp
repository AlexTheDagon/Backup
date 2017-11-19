#include <iostream>
#include <fstream>
using namespace std;
ifstream in("custi.in");
ofstream out("custi.out");
int a[1001][1001],n,m[1001];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            in>>a[i][j];
            if(a[i][j]==1)++m[1];
        }
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=2;j<=n;++j)
        {
            if(a[i][j]==1)
            {
                a[i][j]=min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]))+1;
            }
        }
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=2;j<=n;++j)
        {
            if(a[i][j]==1)
            {
                a[i][j]=min(a[i-1][j],a[i][j-1]);
                if(a[i-a[i-1][j]][j-a[i][j-1]]==1)++a[i][j];
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]>1)m[a[i][j]]++;
        }
    }
    for(int i=n;i>2;--i)m[i-1]+=m[i];
    for(int i=1;i<=n;++i)out<<m[i]<<'\n';
    return 0;
}
