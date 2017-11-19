#include <iostream>

using namespace std;
long long a[100002],n,b[100002];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    b[n]=a[n];
    for(int i=n-1;i>=1;--i)
    {
        b[i]=a[i]+a[i+1];
    }
    for(int i=1;i<=n;++i)cout<<b[i]<<" ";

    return 0;
}
