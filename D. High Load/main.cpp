#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define NM 200005
using namespace std;
int n,k,dist;
vector<int> v;
vector<pair<int,int> > sol;
int main()
{
    cin>>n>>k;
    v.pb(1);
    for(int i=2;i<=k+1;++i)
    {
        v.pb(i);
        sol.pb(mp(1,i));
    }
    for(int i=k+2;i<=n;++i)
    {
        v.pb(i);
        sol.pb(mp(i,v[i-k-1]));
    }
    --n;
    while(n>=k)
    {
        n-=k;
        dist+=2;
    }
    if(n==1)++dist;
    if(n>1)dist+=2;
    cout<<dist<<endl;
    for(auto i:sol)cout<<i.x<<" "<<i.y<<endl;
    return 0;
}
