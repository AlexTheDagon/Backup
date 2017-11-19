#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("omogene.in");
ofstream fout("omogene.out");
#define egal 68000
#define pb push_back
long long n,m,x,sol,cnt,aux,s,sz;
vector <int>v[160000];
vector <int>act;
int main()
{
    fin>>n>>m;
    int a[n+3][m+3],b[n+3][m+3];
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)a[i][j]=0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)b[i][j]=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            fin>>x;
            if(x==0){a[i][j]=-1;b[i][j]=0;}
            else if(x==1){a[i][j]=0;b[i][j]=-1;}
            else {a[i][j]=1;b[i][j]=1;}
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
            b[i][j]+=(b[i-1][j]+b[i][j-1]-b[i-1][j-1]);
        }

    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            s=0;
            sz=0;
            for(int k=1;k<=m;++k)
            {
                    s=a[j][k]-a[i-1][k];
                    sz=b[j][k]-b[i-1][k];
                    if(v[s+egal].size()==0)act.pb(s+egal);
                    v[s+egal].pb(sz);
            }
            for(auto k : act)
            {
                if(k==68000)
                {
                    for(auto h : v[k])
                        if(h==0)sol++;
                }
                sort(v[k].begin(),v[k].end());
                aux=-1000000;cnt=1;
                for(auto h : v[k])
                {
                    if(aux!=h)
                    {
                        sol+=(cnt*(cnt-1)/2);
                        aux=h;
                        cnt=1;
                    }
                    else cnt++;
                }
                sol+=(cnt*(cnt-1)/2);
                v[k].clear();
            }
            act.clear();
        }
    }
    fout<<sol;
    return 0;
}
