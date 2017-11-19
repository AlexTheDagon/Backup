#include <iostream>

using namespace std;
int n,k,p,zile,buz;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>p;
        buz+=(p/k);
        if(p%k)++buz;
    }
    cout<<buz/2+buz%2;
    return 0;
}
