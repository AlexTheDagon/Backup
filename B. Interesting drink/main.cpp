#include <iostream>

using namespace std;
int n,a[100001],q,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=100000;++i)
    {
        a[i]=a[i-1]+a[i];
    }
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>x;
        cout<<a[min(x,100001)]<<'\n';
    }
    return 0;
}
