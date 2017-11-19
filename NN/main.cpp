#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define NM 100005
#define x first
#define y second
using namespace std;
const long double inf=1e9;
ifstream in("nn.in");
ofstream out("nn.out");
int n,m,a,b,baraje[NM];
vector<long double>::iterator low,up;
vector<long double> mal;
pair <long double,long double> bar[NM];
long double tg(int i,int j)
{
    if(i==0)return inf;
    return (1.0*j)/(1.0*i);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b;
        mal.push_back(tg(a,b));
    }
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        bar[i].x=tg(a,b);
        in>>a>>b;
        bar[i].y=tg(a,b);
        if(bar[i].x>bar[i].y)swap(bar[i].x,bar[i].y);
    }
    sort(mal.begin(),mal.begin()+n);
    for(int i=1;i<=m;++i)
    {
        low=lower_bound(mal.begin(),mal.begin()+n,bar[i].x);
        up=upper_bound(mal.begin(),mal.begin()+n,bar[i].y)-1;
        out<<max(up-low,0)<<'\n';
    }
    return 0;
}
