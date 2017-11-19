#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1001],b[1001],k=1,sem;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    if(n%2==1)
    {
        b[1]=a[1];
        k++;
        for(int i=3;i<=n;i=i+2)
        {
            b[i]=a[k];
            ++k;
        }
        for(int i=2;i<=n;i=i+2)
        {
            b[i]=a[k];
            ++k;
        }
    }
    else
    {
        for(int i=1;i<=n;i=i+2)
        {
            b[i]=a[k];
            ++k;
        }
        for(int i=2;i<=n;i=i+2)
        {
            b[i]=a[k];
            ++k;
        }
    }
    for(int i=1;i<=n;++i)cout<<b[i]<<" ";

    return 0;
}
