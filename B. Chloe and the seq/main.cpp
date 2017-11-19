#include <iostream>

using namespace std;
long long lg,n,k;
int main()
{
    cin>>n>>k;
    lg=1;
    for(int i=1;i<=n;++i)lg*=2;
    lg=lg-1;
    while(k!=(lg+1)/2)
    {
        --n;
        if(k>(lg+1)/2)k-=(lg+1)/2;
        lg=(lg-1)/2;
    }
    cout<<n;
    return 0;
}
