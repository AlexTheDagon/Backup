#include <iostream>
#include <fstream>
using namespace std;
ifstream in("rf.in");
ofstream out("rf.out");
int dmin[300][300],m[300][300],n;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            in>>dmin[i][j];
            if(dmin[i][j])m[i][j]=1;
        }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j && dmin[i][k]!=0 && dmin[k][j]!=0)
                {
                    if(dmin[i][k]+dmin[k][j]<dmin[i][j] || dmin[i][j]==0)
                    {
                        dmin[i][j]=dmin[i][k]+dmin[k][j];
                        m[i][j]=m[i][k]+m[k][j];
                    }
                    else
                    {
                        if(dmin[i][k]+dmin[k][j]==dmin[i][j])
                        {
                            m[i][j]=max(m[i][j],m[i][k]+m[k][j]);
                        }
                    }
                }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            out<<dmin[i][j]<<" ";
        }
        out<<'\n';
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            out<<m[i][j]<<" ";
        }
        out<<'\n';
    }
    return 0;
}
