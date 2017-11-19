#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 32100
#define x first
#define y second
using namespace std;
ifstream in("ninjago.in");
ofstream out("ninjago.out");
struct eee
{
    int n1,n2,cost,sem=0;
    string obs;
    bool operator < (const eee &a) const
    {
        return cost<a.cost;
    }
};
eee srt[NM];
int p[NM],n,m,caz,po[]={1,5,25,125},aux,leg,costleg,nremin,nod1,nod2,sol1,viz[NM],dp[NM];
vector <pair<pair<int,int> ,pair<int,int> > > v;
vector<int> vec[NM];
string s;
int dfs(int nod)
{
    viz[nod]=1;
    dp[nod]=1;
    for(auto i:vec[nod])
        if(!viz[i])
            dp[nod]+=dfs(i);
    return dp[nod];
}
int father(int nod)
{
    if(p[nod]==nod)return nod;
    return p[nod]=father(p[nod]);
}
void unire(int xx,int yy)
{
    int f1=father(max(xx,yy));
    int f2=father(min(xx,yy));
    p[max(f1,f2)]=min(f1,f2);
}
int main()
{
    in>>caz>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>srt[i].n1>>srt[i].n2>>srt[i].obs;
        s=srt[i].obs;
        aux=0;
        for(int j=0;j<4;++j)
        {
            if(s[j]!='E')aux+=(s[j]-'A'+1)*po[j];
            else srt[i].sem+=1;
        }
        srt[i].cost=aux;
    }
    sort(srt+1,srt+m+1);
    ///de aici facem Kruskal
    for(int i=1;i<=n;++i)p[i]=i;
    for(int i=1;i<=m && leg<n;++i)
    {
        nod1=srt[i].n1;
        nod2=srt[i].n2;
        if(srt[i].sem)
            v.pb({{srt[i].sem,srt[i].cost},{nod1,nod2}});
        else
        {
            if(father(nod1)!=father(nod2))
            {
                vec[nod1].pb(nod2);
                vec[nod2].pb(nod1);
                unire(nod1,nod2);
                costleg+=srt[i].cost;
                ++leg;
            }
        }
    }
    if(caz==1)
    {
        out<<dfs(1);
        return 0;
    }
    if(caz==2)
    {
        out<<n-1-leg<<'\n';
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size() && leg<n;++i)
    {
        nod1=v[i].y.x;
        nod2=v[i].y.y;
        if(father(nod1)!=father(nod2))
        {
            nremin+=v[i].x.x;
            costleg+=v[i].x.y;
            unire(nod1,nod2);
        }
    }
    if(caz==2)out<<nremin;
    else out<<costleg;
    return 0;
}
