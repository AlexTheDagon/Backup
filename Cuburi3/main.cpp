#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#define x first.first
#define y first.second
#define z second
#include <vector>
#define pb push_back
using namespace std;
ifstream in("cuburi3.in");
ofstream out("cuburi3.out");
pair < pair <int,int> ,int> a[4001];
int n,dp[4005],venit[4005],maxx,ind,h,cub;
vector <int> v;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i].x>>a[i].y;
        a[i].z=i;
    }
    sort(a+1,a+n+1,greater<pair<pair<int,int>,int> >());
    for(int i=1;i<=n;++i)
    {
        maxx=0;
        ind=0;
        for(int j=i-1;j>0;--j)
        {
            if(a[j].y>=a[i].y && dp[j]>maxx)
            {
                maxx=dp[j];
                ind=j;
            }
        }
        dp[i]=maxx+a[i].x;
        venit[i]=ind;
    }
    maxx=0;
    for(int i=1;i<=n;++i)
    {
        if(dp[i]>maxx)
        {
            maxx=dp[i];
            ind=i;
        }
    }
    while(ind!=0)
    {
        v.pb(a[ind].z);
        h+=a[ind].x;
        ind=venit[ind];
    }
    out<<v.size()<<" "<<h<<'\n';
    for(int i=v.size()-1;i>=0;--i)out<<v[i]<<'\n';
    return 0;
}
