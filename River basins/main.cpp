#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define NM 10005
#define pb push_back
using namespace std;
pdd crd[NM];
int n;
stack<pii> s;
double det(pdd A,pdd B,pdd C)
{
    return A.x*B.y+B.x*C.y+C.x*A.y-B.y*C.x-C.y*A.x-A.y*B.x;
}
double dist(pdd A,pdd B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double aria(pdd A,pdd B,pdd C)
{
    double p=(dist(A,B)+dist(A,C)+dist(B,C))/2.0;
    return sqrt(p*(p-dist(A,C))*(p-dist(A,B))*(p-dist(B,C)));
}
bool cmp(int a,int b)
{
    return(atan2(crd[a].x,crd[a].y)>atan2(crd[b].x,crd[b].y));
}
double SSS,SM;
vector<int> sol;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        --t;
        SSS=0;
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>crd[i].x>>crd[i].y;
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
        for(int i=1;i<sol.size()-1;++i)
            SSS+=aria(crd[0],crd[i],crd[i+1]);
        cout<<SSS<<endl;
        SM=max(SM,SSS);
        sol.clear();
        while(!s.empty())s.pop();
    }
    cout<<fixed<<setprecision(6)<<SM;
    return 0;
}
