#include <iostream>

using namespace std;
int n,m,a[1005][1005],s,x,ii,jj,sem;
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m && a[i][j]!=-1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            {cin>>a[i][j];a[i][j]=-a[i][j];}
    for(int i=1;i<=n;++i)
    {
        sem=0;
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==-1)sem=1;
            else a[i][j]+=sem;
        }
    }
    for(int i=1;i<=n;++i)
    {
        sem=0;
        for(int j=m;j>0;--j)
        {
            if(a[i][j]==-1)sem=1;
            else a[i][j]+=sem;
        }
    }
    for(int j=1;j<=m;++j)
    {
        sem=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i][j]==-1)sem=1;
            else a[i][j]+=sem;
        }
    }
    for(int j=1;j<=m;++j)
    {
        sem=0;
        for(int i=n;i>0;--i)
        {
            if(a[i][j]==-1)sem=1;
            else a[i][j]+=sem;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)if(a[i][j]!=-1)s+=a[i][j];
    cout<<s;
    return 0;
}
