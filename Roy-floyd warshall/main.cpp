#include <iostream>
#include <fstream>
using namespace std;
ifstream in("royfloyd.in");
ofstream out("royfloyd.out");
int n,dmin[105][105];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>dmin[i][j];
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j && dmin[i][k]!=0 && dmin[k][j]!=0 && (dmin[i][j]>dmin[i][k]+dmin[k][j] || dmin[i][j]==0))dmin[i][j]=dmin[i][k]+dmin[k][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            out<<dmin[i][j]<<" ";
        }
        out<<'\n';
    }
    return 0;
}
