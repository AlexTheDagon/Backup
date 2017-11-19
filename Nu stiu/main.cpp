#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 10005
using namespace std;
ifstream in("nustiu.in");
ofstream out("nustiu.out");
vector <int> v[NM];
int t,n,x,y,dp[NM],viz[NM],sol,bun[NM];
int dfs(int nod)
{
    viz[nod]=1;
    int sem=1;
    for(auto i:v[nod])
        if(dp[i]>n/2)sem=0;
    if(sem)bun[nod]=1;;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            dp[nod]=n-dp[i];
            dp[i]=n;
            dfs(i);
            dp[i]=n-dp[nod];
            dp[nod]=n;
        }
    }
}
int dfsdp(int nod)
{
    viz[nod]=1;
    for(auto i:v[nod])
        if(!viz[i])
            dp[nod]+=dfsdp(i);
    return dp[nod];
}
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>n;
        for(int i=1;i<=n;++i)dp[i]=1;
        for(int i=1;i<=n;++i)v[i].clear();
        for(int i=1;i<=n;++i)bun[i]=0;
        for(int i=1;i<=n;++i)viz[i]=0;
        for(int i=1;i<n;++i)
        {
            in>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        dfsdp(1);
        for(int i=1;i<=n;++i)viz[i]=0;
        dfs(1);
        for(int i=1;i<=n;++i)if(bun[i])out<<i<<'\n';
    }
    return 0;
}
