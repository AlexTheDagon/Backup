#include <iostream>
#include <algorithm>
using namespace std;
int n,ts,tf,maxx;
pair <int,int> t[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>t[i].second>>t[i].first;
    }
    sort(t+1,t+n+1);
    tf=t[1].first;
    ts=t[1].second;
    maxx=1;
    for(int i=2;i<=n;++i)
    {
        if(t[i].second>=tf)
        {
            ts=t[i].second;
            tf=t[i].first;
            maxx++;
        }
    }
    cout<<maxx;
    return 0;
}
