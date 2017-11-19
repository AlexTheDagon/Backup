#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
vector <int> v[150005];
long long n,m,sem,tot,noduri;
long long a,b,viz[150005];
int dfs(int nod)
{
    ++noduri;
    tot+=v[nod].size();
    viz[nod]=1;
    for(auto i:v[nod])
    {
        if(viz[i]==0)
        {
            dfs(i);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    sem=1;
    for(int i=1;i<=n;++i)
    {
        if(viz[i]==0)
        {
            noduri=0;
            tot=0;
            dfs(i);
            if(noduri*(noduri-1)!=tot && noduri>2)sem=0;
        }
    }
    if(sem)cout<<"YES";
    else cout<<"NO";
    return 0;
}
