#include <iostream>
#include <iomanip>
#define r 10000000000
#define l -10000000000
using namespace std;
double x[60005],v[60005],n,ll,rr,leftt,righttt,md;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i];
    for(int i=1;i<=n;++i)cin>>v[i];
    ll=0;
    rr=r;
    for(int t=1;t<=100;++t)
    {
        md=(ll+rr)/2.0;
        leftt=l;
        righttt=r;
        for(int i=1;i<=n;++i)
        {
            leftt=max(leftt,x[i]-v[i]*md);
            righttt=min(righttt,x[i]+v[i]*md);
        }
        if(righttt>leftt)rr=md;
        else ll=md;
    }
    cout<<fixed<<setprecision(8)<<ll;
    return 0;
}
