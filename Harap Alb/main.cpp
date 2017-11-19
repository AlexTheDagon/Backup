#include <iostream>

using namespace std;
int n,a[1005],sol,minn,p;
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int j=i;
        while(a[j]<a[j-1] && j>1)
        {
            swap(a[j],a[j-1]);
            --j;
        }
    }
    for(int i=n;i>max(0,n-p) && a[i]>0;--i)
        sol+=a[i];
    if(-a[1]>a[n-p+1])
    {
        sol-=a[n-p+1];
        sol-=a[1];
    }
    cout<<sol;
    return 0;
}
