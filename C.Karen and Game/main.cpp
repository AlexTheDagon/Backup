#include <iostream>
#define NM 105
using namespace std;
int g[NM][NM],n,m,minn=1000000000,dif,col[NM],row[NM],sem,sol;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)cin>>g[i][j];
    for(int i=1;i<=m;++i)minn=min(minn,g[1][i]);
    for(int j=1;j<=m;++j)
    {
        dif=g[1][j]-minn;
        col[j]=dif;
        sol+=dif;
        for(int i=1;i<=n;++i)
        {
            g[i][j]-=dif;
        }
    }
    minn=1000000000;
    for(int i=1;i<=n;++i)minn=min(minn,g[i][1]);
    for(int i=1;i<=n;++i)
    {
        dif=g[i][1]-minn;
        row[i]=dif;
        sol+=dif;
        for(int j=1;j<=m;++j)
        {
            g[i][j]-=dif;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)if(g[i][j]!=g[1][1])sem=1;
    if(sem==1)cout<<"-1";
    else
    {
        sol+=g[1][1]*min(n,m);
        cout<<sol<<'\n';
        for(int i=1;i<=n;++i)
        {
            while(row[i])
            {
                cout<<"row "<<i<<'\n';
                --row[i];
            }
        }
        for(int i=1;i<=m;++i)
        {
            while(col[i])
            {
                cout<<"col "<<i<<'\n';
                --col[i];
            }
        }
        if(n<m)
        {
            for(int i=1;i<=n;++i)
                for(int j=1;j<=g[1][1];++j)cout<<"row "<<i<<'\n';
        }
        else
        {
            for(int i=1;i<=m;++i)
                for(int j=1;j<=g[1][1];++j)cout<<"col "<<i<<'\n';
        }
    }
    return 0;
}
