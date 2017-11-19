#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
int dmin[10005][55],cost,venit[10005][55],n,k,minn=100000000,ind,ad,ii,icur,pre;
vector <int> v;
string s;
int main()
{
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=k;++j)
        {
            dmin[i][j]=100000000;
            for(int p=0;p<=j;++p)
            {
                cost=0;
                if(s[i-1]=='1' && (i+j)%10==0)cost=1;
                cost+=(((i-1+p)%10+j-p)/10);
                if(dmin[i-1][p]+cost<dmin[i][j])
                {
                    dmin[i][j]=dmin[i-1][p]+cost;
                    venit[i][j]=p;
                }
            }
        }
    }
    for(int i=0;i<=k;++i)
    {
        if(minn>dmin[n][i])
        {
            minn=dmin[n][i];
            ind=i;
        }
    }
    cout<<minn<<'\n';
    cout<<ind<<" ";
    icur=n;
    pre=ind;
    while(icur>=0)
    {
        if(ind!=pre)
        {
            for(int i=ind;i<pre;++i)v.pb(icur+i+1);
        }
        pre=ind;
        ind=venit[icur][ind];
        --icur;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
    return 0;
}
