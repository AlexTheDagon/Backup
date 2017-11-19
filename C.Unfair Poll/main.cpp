#include <iostream>
#include <vector>
#define mp make_pair
#define f first
#define s second
using namespace std;

long long a[101][101],k,minn=1000000000000000000000,maxx,p;
int n,m,x,y,t;
vector< pair<int , int> > v;
int main()
{
    cin>>n>>m>>k>>x>>y;
    if (n==1)
    {
        for (int i=0;i<m;++i)
            v.push_back(mp(1,i+1));
    }
    else
    {
        for(int i=1;i<n;++i)
        {
            for (int j = 1 ; j <= m ; ++ j)
                v.push_back(mp(i,j));
        }
        for(int i=1;i<n;++i)
        {
            for (int j=1;j<=m;++j)
                v.push_back(mp(n-i+1,j));
        }
    }
    t=v.size();
    p=k/t;
    for(auto it:v)
        a[it.f][it.s]+=p;
    k%=t;
    for(auto it:v)
    {
        if(k>0)
        {
            --k;
            ++a[it.f][it.s];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            minn=min(minn,a[i][j]);
            maxx=max(maxx,a[i][j]);
        }
    }
    cout<<maxx<<' '<<minn<<' '<<a[x][y]<<endl;
    return 0;
}
///ajutor sursa
