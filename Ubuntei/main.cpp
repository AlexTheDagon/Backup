#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <bitset>
#define pb push_back
#define NM 2005
using namespace std;
ifstream in("ubuntzei.in");
ofstream out("ubuntzei.out");
struct eee
{
    int nod,cost;
    bool operator < (const eee &a) const
    {
        return cost>a.cost;
    }
};
priority_queue<eee> q;
vector<eee> v[NM];
int n,m,dp[(1<<15)][20],dmin[NM][NM],c[20],k,x,y,z,ind[NM],sol=(1<<25);
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=k;++i)
        in>>c[i];
    c[0]=1;
    c[k+1]=n;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y>>z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    dmin[1][1]=0;
    q.push({1,0});
    for(int i=0;i<=k+1;++i)
        for(int j=1;j<=n;++j)dmin[c[i]][j]=(1<<25);
    for(int i=0;i<=k+1;++i)
    {
        for(int j=1;j<=n;++j)dmin[c[i]][j]=(1<<25);
        dmin[c[i]][c[i]]=0;
        q.push({c[i],0});
        while(!q.empty())
        {
            int nod=q.top().nod,cost=q.top().cost;
            q.pop();
            if(cost!=dmin[c[i]][nod])continue;
            for(auto s:v[nod])
            {
                if(dmin[c[i]][s.nod]>dmin[c[i]][nod]+s.cost)
                {
                    dmin[c[i]][s.nod]=dmin[c[i]][nod]+s.cost;
                    q.push({s.nod,dmin[c[i]][s.nod]});
                }
            }
        }
    }
    if(k==0)out<<dmin[1][n];
    else
    {
        for(int i=0;i<(1<<k);++i)
            for(int j=0;j<=k;++j)dp[i][j]=(1<<25);
        for(int i=1;i<=k;++i)
            dp[1<<(i-1)][i]=dmin[1][c[i]];
        for(int config=2;config<(1<<k);++config)
            for(int j=0;j<k;++j)
                if(config&(1<<j))
                    for(int jj=1;jj<=k;++jj)
                        dp[config][j+1]=min(dp[config][j+1],dp[config-(1<<j)][jj]+dmin[c[jj]][c[j+1]]);
        for(int i=1;i<=k;++i)sol=min(sol,dp[(1<<k)-1][i]+dmin[c[i]][n]);
        out<<sol;
    }
    return 0;
}
