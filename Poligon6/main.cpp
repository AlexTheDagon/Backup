#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define f first
#define sf second.first
#define ss second.second
using namespace std;
ifstream in("poligon6.in");
ofstream out("poligon6.out");
int n,d[1005],s,di;
short m[1005][1005];
vector<pair<double,pair<int,int> > > v;
double tg,x;
int cmmdc(int a,int b)
{
    int c=0;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>d[i];
        for(int j=1;j<d[i];++j)
        {
            x=sqrt(d[i]*d[i]-j*j);
            if(x==(int)(x))
            {
                tg=1.0*j/x;
                ++s;
                di=cmmdc(j,(int)(x));
                ++m[j/di][(int)(x)/di];
                if(m[j/di][(int)(x)/di]==1)v.pb(mp(tg,mp(j/di,x/di)));
            }
        }
    }
    out<<s<<'\n'<<v.size()<<'\n';
    sort(v.begin(),v.end());
    for(auto i:v)out<<m[i.sf][i.ss]<<" ";
    ///for(map<double,int>::iterator it=m.begin();it!=m.end();++it)out<<(*it).second<<" ";
    return 0;
}
