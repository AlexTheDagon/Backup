#include <iostream>
#define NM 1000005
using namespace std;
int g[NM],n,k,a,b,cur,m;
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>cur;
        g[cur]=1;
    }
    cur=1;
    for(int i=1;i<=k && g[cur]==0;++i)
    {
        cin>>a>>b;
        if(a==cur)cur=b;
        else if(b==cur)cur=a;
    }
    cout<<cur;
    return 0;
}
