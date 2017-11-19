#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <functional>
#define x first.first
#define y first.second
#define z second
#define mp make_pair
using namespace std;
ifstream in("zmeu2.in");
ofstream out("zmeu2.out");
pair<pair<int,int>,int > fr;
priority_queue< pair<pair<int,int>,int >,vector <pair<pair<int,int>,int > > ,greater<pair<pair<int,int>,int> > > q;
int dp[205];
bool da[205][205];
int n,m,a,b,p,k,d[205],c[205],sem,sol;
int main()
{
    in>>n>>p>>k;
    for(int i=1;i<=p;++i)
    {
        dp[i]=1000000000;
        da[i][i]=1;
    }
    for(int i=1;i<=p;++i)
        for(int j=1;j<=p;++j)da[i][j]=1;
    for(int i=1;i<=p;++i)in>>d[i]>>c[i];
    for(int i=1;i<=k;++i)
    {
        in>>a>>b;
        da[a][b]=0;
    }
    da[1][p]=0;
    q.push(mp(mp(d[1],1),n-c[1]));
    while(!q.empty())
    {
        fr=q.top();
        q.pop();
        for(int i=1;i<=p;++i)
        {
            if(da[fr.y][i]==1 && fr.z-c[i]>0 && fr.x+d[i]<dp[i])
            {
                dp[i]=fr.x+d[i];
                q.push(mp(mp(fr.x+d[i],i),fr.z-c[i]));
            }
        }
    }
    if(dp[p]!=1000000000)out<<dp[p];
    else out<<"-1";
    return 0;
}
