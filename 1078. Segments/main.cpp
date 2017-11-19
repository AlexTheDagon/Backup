#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define x first
#define y second
using namespace std;
pair <int,int> a[505];
pair <pair <int,int>,int> ind[505];
int dp[505],parinte[505];
int n,maxx,imax;
vector <int> v;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x>>a[i].y;
        ind[i].x.x=a[i].x;
        ind[i].x.y=a[i].y;
        ind[i].y=i;
    }
    sort(ind+1,ind+n+1);
    sort(a+1,a+n+1);
    a[0].x=-100000;
    a[0].y=1000000;
    for(int i=1;i<=n;++i)
    {
        for(int j=i-1;j>=0;--j)
        {
            if(a[i].x>a[j].x && a[i].y<a[j].y && dp[j]>=dp[i])
            {
                dp[i]=dp[j]+1;
                parinte[i]=j;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(dp[i]>maxx)
        {
            maxx=dp[i];
            imax=i;
        }
    }
    while(imax!=0)
    {
        v.pb(imax);
        imax=parinte[imax];
    }
    cout<<maxx<<'\n';
    for(int i=0;i<v.size();++i)cout<<ind[v[i]].y<<" ";
    return 0;
}
