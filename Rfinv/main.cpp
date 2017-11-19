#include <iostream>
#include <fstream>
using namespace std;
ifstream in("rfinv.in");
ofstream out("rfinv.out");
int n,m,t,d[55][55],sem,a,b,c,dmin[55][55],s[55][55];
int main()
{
    in>>t;
    for(int T=1;T<=t;++T)
    {
        for(int i=1;i<=50;++i)
            for(int j=1;j<=50;++j)
            {
                d[i][j]=0;
                dmin[i][j]=0;
                s[i][j]=0;
            }
        in>>n>>m;
        for(int i=1;i<=m;++i)
        {
            in>>a>>b;
            s[a][b]=1;
            s[b][a]=1;
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)in>>dmin[i][j];
        sem=0;
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(i!=j)
                    {
                        if(dmin[i][k] && dmin[k][j] && (dmin[i][j]>dmin[i][k]+dmin[k][j] || dmin[i][j]==0))
                        {
                            sem=1;
                        }
                    }
                }
            }
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(i!=j)
                    {
                        if(dmin[i][k] && dmin[k][j] && dmin[i][j]==dmin[i][k]+dmin[k][j])
                        {
                            s[i][j]=1;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(dmin[i][j] && !s[i][j])sem=1;
            }
        }
        if(sem==1)out<<"NU"<<'\n';
        else out<<"DA"<<'\n';
    }
    return 0;
}
