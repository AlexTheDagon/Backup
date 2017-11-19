#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 16005
#include <queue>
using namespace std;
ifstream in("sediu.in");
ofstream out("sediu.out");
int n,a,b,dp[NM],h[NM],viz[NM],dpm,hm,maxx[NM],nodm,maxim,nrsol;
vector <int> v[NM];
int dfs(int nod)
{
    viz[nod]=1;
    dp[nod]=1;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            h[i]=h[nod]+1;
            dp[nod]+=dfs(i);
        }
    }
    return dp[nod];
}
int main()
{
    in>>n;
    h[1]=1;
    for(int i=1;i<n;++i)
    {
        in>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    maxim=NM;
    ///bine
    for(int i=1;i<=n;++i)
    {
        hm=NM;
        for(auto j:v[i])
        {
            if(hm>h[j])
            {
                hm=h[j];
                dpm=dp[j];
                nodm=j;
            }
            if(hm==h[j] && dp[j]>dpm)
            {
                dpm=dp[j];
                nodm=j;
            }
        }
        ///bine
        int aux;
        maxx[i]=n-dp[i];
        for(auto j:v[i])
        {
            if(j!=nodm)
            {
                maxx[i]=max(maxx[i],dp[j]);
                maxx[i]=max(maxx[i],dp[j]);
            }
        }
        if(i==1)maxx[i]=dpm;///radacina
        maxim=min(maxim,maxx[i]);
    }
    ///dupa e bine
    for(int i=1;i<=n;++i)if(maxx[i]==maxim)++nrsol;
    out<<maxim<<" "<<nrsol<<'\n';
    for(int i=1;i<=n;++i)if(maxx[i]==maxim)out<<i<<" ";

    return 0;
}
