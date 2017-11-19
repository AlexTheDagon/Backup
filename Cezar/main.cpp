#include <queue>
#include <vector>
#include <cstdio>
#include <bitset>
#define pb push_back
#define NM 10001
#define mp make_pair
#define x first
#define y second
using namespace std;
short n,k;
bitset<NM> bs;
vector <short> v[NM],d;
short cost[NM],a,b;
FILE * fi = fopen("cezar.in", "r");
FILE * fo = fopen("cezar.out", "w");
priority_queue <pair <short, short> > q;
pair <short, short> fr;
int main()
{
    fscanf(fi, "%hd %hd", &n, &k);
    for(short i=1;i<n;++i)
    {
        fscanf(fi, "%hd %hd", &a, &b);
        cost[a]=cost[b]=1;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(short i=1;i<=n;++i)
        if(v[i].size()==1)
        {
            bs[i]=1;
            q.push(mp(-cost[i],i));
        }
    ///initializat coada
    long long sol=0,b=n;
    while (!q.empty())
    {
        a=q.top().y;
        q.pop();
        --b;
        for(int i=0;i<v[v[a][0]].size();++i)if(v[v[a][0]][i]==a)v[v[a][0]].erase(v[v[a][0]].begin()+i);
        cost[v[a][0]]+=cost[a];
        if(v[v[a][0]].size()==1)
        {
            q.push(mp(-cost[v[a][0]],v[a][0]));
            bs[v[a][0]]=1;
        }
        if(b<k+1)d.push_back(a);
    }
    for(int i=1;i<=n;++i)sol+=cost[i];
    for(auto i:d)sol-=cost[i];
    fprintf(fo, "%lld", sol);
    return 0;
}
