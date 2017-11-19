#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair
#define NMAX 50005
#define MMAX 250005
#define inf (1<<30)
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int a,b,c;
int n,m;
vector<int> v[NMAX],cost[NMAX];
int dmin[NMAX],fol[NMAX],inv[NMAX];
int minn;
vector <int > v;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)dmin[i]=inf;
    dmin[1]=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)lista[i][j]=-1;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        lista[a][b]=c;
    }
    int nod;
    v.pb(1);
    inv[1]=1;
    for(int i=1;i<=n;++i)
    {
        minn=inf;
        for(auto j:v)
        {
            if(fol[j]==0)
            {
                if(dmin[j]<minn)
                {
                    nod=j;
                    minn=dmin[j];
                }
            }
        }
        fol[nod]=1;
        for(int j=1;j<=n;++j)
        {
            if(lista[nod][j]>-1)
            {
                dmin[j]=min(dmin[nod]+lista[nod][j],dmin[j]);
                if(inv[j]==0)
                {
                    inv[j]=1;
                    v.pb(j);
                }
            }
        }
    }
    for(int i=2;i<=n;++i)
    {
        if(dmin[i]==inf)out<<"0 ";
        else out<<dmin[i]<<" ";
    }
    return 0;
}
