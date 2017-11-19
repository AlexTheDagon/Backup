#include <iostream>
#include <cmath>
#include <fstream>
#include <queue>
#include <functional>
#define NM 100005
#define f first
#define s second
#define mp make_pair
using namespace std;
ifstream in("secv4.in");
ofstream out("secv4.out");
double a[NM],m[2*NM];
int s[NM];
int n,x,y;
int l,st;
double p;
priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > q[3];
pair<double,int> fr;
int main()
{
    in>>n>>x>>y;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        if(a[i]<0)
        {
            s[i]=-1;
            a[i]*=-1;
        }
        else s[i]=1;
        a[i]=log(a[i]);
        m[i+x]=a[i];
    }
    s[0]=1;
    for(int i=1;i<=n;++i)
    {
        m[i]+=m[i-1];
        a[i]+=a[i-1];
        s[i]*=s[i-1];
    }
    ///bine
    for(int i=x;i<=n;++i)
    {
        q[1-s[i-x]].push(mp(m[i],i-x));
        if(!q[1-s[i]].empty())fr=q[1-s[i]].top();
        while(i-fr.s>y && !q[1-s[i]].empty())
        {
            q[1-s[i]].pop();
            fr=q[1-s[i]].top();
        }
        if((a[i]-fr.f)>p && !q[1-s[i]].empty())
        {
            st=fr.s+1;
            l=i-fr.s;
            p=a[i]-fr.f;
        }
    }
    out<<l<<" "<<st;
    return 0;
}
