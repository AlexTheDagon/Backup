#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
vector <int> v[1005];
int n,a,b,k,c[1005];
void dfs(nod,nodant)
{
    if(v[nod].size()==1)
    {

    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    return 0;
}
c[nod]--->1 daca castiga cel ce face mutarea
      --->0 daca pierde cel ce face mutarea
