#include <iostream>
#include <string.h>
using namespace std;
int n,a[105];
int s(int i)
{
    if(i>n)return 0;
    return s(i+1)+a[i];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cout<<1.0*s(1)/n;
    return 0;
}
