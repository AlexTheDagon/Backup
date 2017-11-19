#include <iostream>

using namespace std;
int n,a[56];
int main()
{
    cin>>n;
    a[1]=1;
    a[2]=1;
    a[3]=2;
    for(int i=4;i<=n;++i)a[i]=a[i-1]+a[i-3]+1;
    cout<<a[n];
    return 0;
}
