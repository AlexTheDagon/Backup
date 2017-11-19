#include <iostream>

using namespace std;
int n,x,nr;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(x==1)nr++;
    }
    if((n==nr+1 && n>1) || (n==1 && nr==1))cout<<"YES";
    else cout<<"NO";
    return 0;
}
