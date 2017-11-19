#include <iostream>

using namespace std;
int a,b,c,maxx;
int main()
{
    cin>>a>>b>>c;
    maxx=max(a+b+c,max((a+b)*c,max(a*(b+c),a*b*c)));
    cout<<maxx;
    return 0;
}
