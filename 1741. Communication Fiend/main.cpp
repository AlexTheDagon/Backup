#include <iostream>
#include <algorithm>
#define mp make_pair
#define x first.first
#define y first.second
#define d second.first
#define s second.second
using namespace std;
long long n,m,p[10005],l[10005];
string sc="Cracked",sl="Licensed",sp="Pirated";
pair<pair<long long,long long>,pair<long long,string> > v[10005];
int main()
{
    cin>>n>>m;
    for(int i=2;i<=n;++i)l[i]=p[i]=10000000000000;
    p[1]=10000000000000;
    for(int i=1;i<=m;++i)cin>>v[i].y>>v[i].x>>v[i].d>>v[i].s;
    for(int i=1;i<=m;++i)swap(v[i].x,v[i].y);
    sort(v+1,v+m+1);
    for(int i=1;i<=m;++i)
    {
        if(v[i].s==sl)l[v[i].y]=min(l[v[i].x]+v[i].d,l[v[i].y]);
        if(v[i].s==sp)
        {
            p[v[i].y]=min(p[v[i].x]+v[i].d,p[v[i].y]);
            p[v[i].y]=min(l[v[i].x]+v[i].d,p[v[i].y]);
        }
        if(v[i].s==sc)
        {
            l[v[i].y]=min(l[v[i].x]+v[i].d,l[v[i].y]);
            p[v[i].y]=min(p[v[i].x]+v[i].d,p[v[i].y]);
        }
    }
    if(min(l[n],p[n])>=10000000000000)cout<<"Offline";
    else cout<<"Online"<<'\n'<<min(l[n],p[n]);
    return 0;
}
