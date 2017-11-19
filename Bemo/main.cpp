#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define pb push_back
using namespace std;
ifstream in("bemo.in");
ofstream out("bemo.out");
int n,m,r,ii,jj;
pair<int,int> p[2300000];
int a[1505][1505];
vector <pair<int,int> > v;
int main()
{
    in>>n>>m;
    r=n+m-1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            p[a[i][j]].x=i;
            p[a[i][j]].y=j;
        }
    }
    for(int i=1;i<=n*m && r;++i)
    {
        if(a[p[i].x][p[i].y]!=-1)
        {
            --r;
            v.pb(p[i]);
            ii=p[i].x;
            jj=p[i].y;
            for(int j=ii+1;j<=n;++j)///der verif
                for(int k=jj-1;k>0 && a[j][k]!=-1;--k)
                    a[j][k]=-1;
            for(int j=ii-1;j>0;--j)///der verif
                for(int k=jj+1;k<=m && a[j][k]!=-1;++k)
                    a[j][k]=-1;
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)out<<a[v[i].x][v[i].y]<<" ";

    return 0;
}
///Umplem o zona pana dam de o zona cu -1(zona umpluta care nu ii bun)
