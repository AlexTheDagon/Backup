#include <iostream>

using namespace std;
long long s,x,n,a[300000],minn=1000000000000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        a[i]=x;
        s+=x;
    }
    s=s/n;
    for(int i=1;i<=n;++i)
    {
        if(s-a[i]<minn && s-a[i]>=0)
        {
            minn=s-a[i];
            x=a[i];
        }
    }
    cout<<x;
    return 0;
}
