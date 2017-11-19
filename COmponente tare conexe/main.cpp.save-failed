#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#define pb push_back
#define NM 100005
#define MM 200005
using namespace std;
ifstream in("ctc.in");
ofstream out("ctc.out");
vector<int> v[NM],sol[NM];
int low[NM],viz[NM],a,b,n,m,init[NM],h,ins[NM],nrsol;
stack<int> s;
void dfs(int nod)
{
    ++h;
    low[nod]=init[nod]=h;
    s.push(nod);
    viz[nod]=1;
    ins[nod]=1;
    for(auto i:v[nod])
    {
        if(viz[i]==0)
        {
            dfs(i);
            low[nod]=min(low[nod],low[i]);
        }
        else
        {
            if(ins[i]==1)low[nod]=min(low[nod],low[i]);
        }
    }
    if(init[nod]==low[nod])
    {
        ++nrsol;
        while(s.top()!=nod)
        {
            ins[s.top()]=0;
            sol[nrsol].pb(s.top());
            s.pop();
        }
        ins[s.top()]=0;
        sol[nrsol].pb(s.top());
        s.pop();
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[a].pb(b);
    }
    for(int i=1;i<=n;++i)
    {
        if(viz[i]==0)
        {
            h=0;
            dfs(i);
        }
    }
    out<<nrsol<<'\n';
    for(int i=1;i<=nrsol;++i)
    {
        for(auto j:sol[i])out<<j<<" ";
        out<<'\n';
    }
    return 0;
}
