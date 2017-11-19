#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <map>
#include <stdlib.h>
#define pb push_back
#define NM 305
#define MM 2005
using namespace std;
ifstream in("plan.in");
ofstream out("plan.out");
vector<int> v[NM],sol[NM],v2[NM];
int low[NM],viz[NM],viz2[NM],a,b,n,m,init[NM],h,ins[NM],nrsol,ctc[NM],fr1[NM],fr2[NM],lies,lint,oras1,oras2,aux,sem;
stack<int> s,s1,s2;
map<pair<int,int>,int> mp;
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
        if(mp.find(make_pair(ctc[nod],ctc[i]))==mp.end() && ctc[nod]!=ctc[i])
            {
                mp[make_pair(ctc[nod],ctc[i])]=1;
                ++fr2[ctc[i]];
                ++fr1[ctc[nod]];
            }
        if(!viz2[i])
        {
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
        if(!fr1[i])
        {
            ++lies;
            s1.push(i);
        }
        if(!fr2[i])
        {
            ++lint;
            s2.push(i);
        }
    }
    nrleg=min(lint,lies)+abs(lint-lies);
    if(nrsol==1)out<<"0";
    else
    {
        out<<nrleg<<'\n';
        oras1=sol[1][0];
        oras2=sol[nrsol][0];
        while(!s1.empty() && !s2.empty())
        {
            if((s1.top()==s2.top() || mp.find(make_pair(s2.top(),s1.top()))!=mp.end()) && s2.size()>1)
            {
                aux=s2.top();
                s2.pop();
                sem=1;
            }
            out<<sol[s1.top()][0]<<" "<<sol[s2.top()][0]<<'\n';
            s2.pop();
            if(sem==1)
            {
                s2.push(aux);
                sem=0;
            }
            s1.pop();
        }
        while(!s2.empty())
        {
            if(sol[s2.top()][0]!=oras1)out<<oras1;
            else out<<oras2;
            out<<" "<<sol[s2.top()][0];
            out<<'\n';
            s2.pop();
        }
        while(!s2.empty())
        {

            out<<sol[s1.top()][0]<<" ";
            if(sol[s1.top()][0]!=oras1)out<<oras1;
            else out<<oras2;
            out<<'\n';
            s1.pop();
        }
    }

    return 0;
}
