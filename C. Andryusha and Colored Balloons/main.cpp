#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
vector <int> v[200005];
int n,x,y;
int col[200005],maxx,p[200005];
void dfs(int nod)
{
    int c=1;
    for(auto i:v[nod])
    {
        if(!col[i])
        {
            while(c==col[nod] || c==col[p[nod]])++c;
            p[i]=nod;
            col[i]=c;
            maxx=max(maxx,c);
            ++c;
            dfs(i);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    p[1]=1;
    col[1]=1;
    dfs(1);
    cout<<maxx<<'\n';
    for(int i=1;i<=n;++i)cout<<col[i]<<" ";
    return 0;
}
