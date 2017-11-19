#include <iostream>

using namespace std;
int n,a,b,c,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        if(a>b)++m;
        if(b>a)++c;
    }
    if(m>c)cout<<"Mishka";
    if(c>m)cout<<"Chris";
    if(c==m)cout<<"Friendship is magic!^^";
    return 0;
}
