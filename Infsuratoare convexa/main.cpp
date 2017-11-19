#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define NM 120005
#define pb push_back
using namespace std;
ifstream in("infasuratoare.in");
ofstream out("infasuratoare.out");
pdd crd[NM];
int n;
stack<pii> s;
double det(pdd A,pdd B,pdd C)
{
    return A.x*B.y+B.x*C.y+C.x*A.y-B.y*C.x-C.y*A.x-A.y*B.x;
}
bool cmp(int a,int b)
{
    return(atan2(crd[a].x,crd[a].y)>atan2(crd[b].x,crd[b].y));
}
vector<int> sol;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>crd[i].x>>crd[i].y;
    sort(crd+1,crd+n+1);
    s.push(mp(0,1));
    for(int i=2;i<=n;++i)
    {
        while(s.size()>1 && det(crd[s.top().x],crd[s.top().y],crd[i])<0.0)s.pop();
        s.push(mp(s.top().y,i));
    }
    while(!s.empty())
    {
        sol.pb(s.top().y);
        s.pop();
    }
    s.push(mp(0,1));
    for(int i=2;i<=n;++i)
    {
        while(s.size()>1 && det(crd[s.top().x],crd[s.top().y],crd[i])>0.0)s.pop();
        s.push(mp(s.top().y,i));
    }
    s.pop();
    while(s.size()>1)
    {
        sol.pb(s.top().y);
        s.pop();
    }
    sort(sol.begin(),sol.end(),cmp);
    out<<sol.size()<<'\n';
    for(auto i:sol)out<<fixed<<setprecision(6)<<crd[i].x<<" "<<crd[i].y<<'\n';

    return 0;
}
