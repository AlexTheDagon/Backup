#include <iostream>

using namespace std;
long long n,m,a,x,y;
int main()
{
    cin>>n>>m>>a;
    x=n/a;
    y=m/a;
    n=n%a;
    m=m%a;
    if(n>0)++x;
    if(m>0)++y;
    cout<<x*y;
    return 0;
}
