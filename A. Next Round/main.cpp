#include <iostream>

using namespace std;
int a[51],n,k,nr;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)if(a[i]>=a[k] && a[i]>0)nr++;
    cout<<nr;
    return 0;
}
