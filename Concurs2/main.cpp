#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
ifstream in("concurs2.in");
ofstream out("concurs2.out");
int n,judete,a,b,ii,jj,limit,ind1,ind2,ind[55],ramasi[55],maxx,imaxx;
vector<int> jud[55];
vector <pair<int,int> > fr,v;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b;
        if(jud[a].size()==0)++judete;
        jud[a].pb(b);
    }
    out<<judete<<'\n';
    for(int i=1;i<=50;++i)
    {
        if(jud[i].size())
        {
            out<<jud[i].size()<<" ";
            sort(jud[i].begin(),jud[i].end());
            fr.pb(mp(jud[i].size(),i));
        }
    }
    out<<'\n';
    for(int i=1;i<=50;++i)ramasi[i]=jud[i].size();
    for(int i=1;i<=n;++i)
    {
        maxx=0;
        for(int j=1;j<=50;++j)
        {
            if(ramasi[j]>maxx && (v.empty() || j!=v[v.size()-1].x))
            {
                maxx=ramasi[j];
                imaxx=j;
            }
        }
        v.pb(mp(imaxx,jud[imaxx][ind[imaxx]]));
        ++ind[imaxx];
        --ramasi[imaxx];
    }
    for(auto i:v)out<<i.x<<" "<<i.y<<'\n';
    return 0;
}
