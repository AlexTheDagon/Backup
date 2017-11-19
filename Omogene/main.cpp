#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NM 5005
#define pb push_back
using namespace std;
ifstream in("omogene.in");
ofstream out("omogene.out");
int n,m;
long long nr,cur,act,s,sz;
vector<int> v[200000],aux;
int main()
{
    in>>n>>m;
    int a[n+3][m+3];
    int z[n+3][m+3];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {

            in>>a[i][j];
            if(a[i][j]==2)z[i][j]=-1;
            else z[i][j]=a[i][j];
            --a[i][j];
        }
    }
    for(int j=0;j<=m;++j)z[0][j]=0;
    for(int j=0;j<=m;++j)a[0][j]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]+=a[i-1][j];
            z[i][j]+=z[i-1][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            s=0;
            sz=0;
            for(int k=1;k<=m;++k)
            {
                s+=(a[j][k]-a[i-1][k]);
                sz+=(z[j][k]-z[i-1][k]);
                if(v[s+100000].size()==0)aux.pb(s+100000);
                v[s+100000].pb(sz);
            }
            for(auto k:aux)
            {
                if(k==100000)
                {
                    for(auto h:v[k])if(h==0)++nr;
                }
                cur=1;
                act=-1000000;
                sort(v[k].begin(),v[k].end());
                for(auto h:v[k])
                {
                    if(act!=h)
                    {
                        nr+=(cur*(cur-1)/2);
                        act=h;
                        cur=1;
                    }
                    else ++cur;
                }
                nr+=cur*(cur-1)/2;
                v[k].clear();
            }
            aux.clear();
        }
    }
    out<<nr;
    return 0;
}
///O(min*min*max)


