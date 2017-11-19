#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define NM 100005
#define pb push_back
using namespace std;
ifstream in("copac.in");
ofstream out("copac.ok");
int dp[NM],n,viz[NM],sem,sol;
vector<int> v[NM];
int dfs(int nod)
{
    viz[nod]=1;
    dp[nod]=1;
    for(auto i:v[nod])
        if(!viz[i])
            dp[nod]+=dfs(i);
    return dp[nod];
}
int main()
{
    in>>n;
    int a,b;
    for(int i=1;i<n;++i)
    {
        in>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=n;++i)
    {
        sem=1;
        for(int j=1;j<=n;++j)dp[j]=viz[j]=0;
        viz[i]=1;
        for(auto j:v[i])if(dfs(j)>(n+1)/2)sem=0;
        if(sem)++sol;
    }
    out<<sol;
    return 0;
}
