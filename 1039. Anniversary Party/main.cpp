#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int n,a[6005],x,y,maxx[6005],viz[6005],maxim=0,m1,m2;
vector <int> v[6005],vv[6005],aux;
int dfs(int nod)
{
    int s1=0,s2=0;
    if(v[nod].size()==0 || viz[nod])
    {
        viz[nod]=1;
        return maxx[nod];
    }
    for(auto i:v[nod])s1+=dfs(i);
    for(auto i:vv[nod])s2+=dfs(i);
    maxx[nod]=max(s1,s2+a[nod]);
    viz[nod]=1;
    return maxx[nod];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)if(a[i]>0)maxx[i]=a[i];
    cin>>x>>y;
    while(x!=0)
    {
        v[y].pb(x);
        cin>>x>>y;
    }
    for(int i=1;i<=n;++i)
        for(auto j:v[i])
            for(auto k:v[j])vv[i].pb(k);
    for(int i=1;i<=n;++i)maxim=max(maxim,dfs(i));
    cout<<maxim;
    return 0;
}
