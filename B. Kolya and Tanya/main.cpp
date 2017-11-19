#include <iostream>
#define modulo 1000000007
using namespace std;
long long n,s,f3=1,f7=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        f3=f3*27%modulo;
        f7=f7*7%modulo;
        s=f3-f7;
        if(s<0)s=s+modulo;
    }
    cout<<s;
    return 0;
}
