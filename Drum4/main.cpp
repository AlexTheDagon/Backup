#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#define pb push_back
#define NM 100005
#define MM 200005
using namespace std;
ifstream in("drum4.in");
ofstream out("drum4.out");
vector<int> v[NM],sol[NM];
int low[NM],viz[NM],viz2[NM],a,b,n,m,init[NM],h,ins[NM],nrsol,ctc[NM],fr[NM];
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
void dfs2(int nod)
{
    viz2[nod]=1;
    for(auto i:v[nod])
    {
        if(!viz2[i])
        {
            if(ctc[i]!=ctc[nod])
            {
                ++fr[ctc[i]];
                ++fr[ctc[nod]];
            }
            dfs2(i);
        }
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
    for(int i=1;i<=nrsol;++i)
        for(auto j:sol[i])ctc[j]=i;
    for(int i=1;i<=n;++i)
    {
        if(!viz2[i])dfs2(i);
    }
    int nrleg=0;
    for(int i=1;i<=nrsol;++i)
    {
        if(fr[i]<2)
        {
            nrleg+=2-fr[i];
        }
    }
    out<<(nrleg+1)/2;
    return 0;
}
///nrsol -nr ctc
///sol[i]-componentele ctc i
