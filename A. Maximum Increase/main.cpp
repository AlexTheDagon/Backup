#include <iostream>

using namespace std;
int a[100001],n,l=1,lmax;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=2;i<=n;++i)
    {
        if(a[i]>a[i-1])++l;
        else
        {
            lmax=max(l,lmax);
            l=1;
        }
    }
    lmax=max(l,lmax);
    cout<<lmax;
    return 0;
}
