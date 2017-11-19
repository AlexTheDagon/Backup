#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
ifstream in("lenes.in");
ofstream out("lenes.out");
int n,m,k1,k2,maxx1[505],maxx2[505],a[505][505],cost[505],caz,aux,minn1,minn2;
vector <int> v;
int main()
{
    in>>caz;
    in>>n>>m>>k1>>k2;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            cost[j]+=a[i][j];
        }
    }
    for(int i=1;i<=m;++i)maxx1[i]=maxx2[i]=1000000000;
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)v.pb(a[i][j]);
        sort(v.begin(),v.end());
        for(int i=1;i<=m;++i)a[i][j]=v[i-1];
        v.clear();
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=2;j<=n;++j)a[j][i]+=a[j-1][i];
    }
    maxx1[1]=a[k1][2];
    maxx1[m]=a[k1][m-1];
    maxx2[1]=a[k2][2];
    maxx2[m]=a[k2][m-1];
    for(int i=2;i<m;++i)
    {
        for(int j=0;j<=k1;++j)maxx1[i]=min(maxx1[i],a[j][i-1]+a[k1-j][i+1]);
        for(int j=0;j<=k2;++j)maxx2[i]=min(maxx2[i],a[j][i-1]+a[k2-j][i+1]);
    }
    minn1=minn2=1000000000;
    for(int i=1;i<=m;++i)minn1=min(minn1,maxx1[i]+cost[i]);
    for(int i=1;i<=m;++i)minn2=min(minn2,maxx2[i]+cost[i]);
    for(int i=1;i<=m;++i)out<<cost[i]<<" ";
    out<<'\n';
    for(int i=1;i<=m;++i)out<<maxx1[i]<<" ";
    out<<'\n';
    for(int i=1;i<=m;++i)out<<maxx2[i]<<" ";
    out<<'\n';
    if(caz==1)out<<minn1;
    else out<<minn1+minn2;
    return 0;
}
