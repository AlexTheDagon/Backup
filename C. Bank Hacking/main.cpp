#include <iostream>
#include <vector>
#define pb push_back
#define NM 300005
using namespace std;
int n,a[NM],viz[NM],maxx=-1000000010,capat,fr1,fr2,sol,x,y;
vector <int> dest[NM],ind;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)maxx=max(maxx,a[i]);
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        dest[x].pb(y);
        dest[y].pb(x);
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]==maxx)++fr1;
        if(a[i]==maxx-1)++fr2;
    }
    sol=maxx+2;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==maxx)--fr1;
        if(a[i]==maxx-1)--fr2;
        for(auto j:dest[i])
        {
            if(a[j]==maxx)
            {
                --fr1;
                ++fr2;
            }
            if(a[j]==maxx-1)--fr2;
        }


        if(fr1==0)
        {
            sol=min(sol,maxx+1);
            if(fr2==0)sol=min(sol,maxx);
        }

        if(a[i]==maxx)++fr1;
        if(a[i]==maxx-1)++fr2;
        for(auto j:dest[i])
        {
            if(a[j]==maxx)
            {
                ++fr1;
                --fr2;
            }
            if(a[j]==maxx-1)++fr2;
        }
    }
    cout<<sol;
    return 0;
}
