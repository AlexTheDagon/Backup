#include <iostream>
#include <algorithm>
using namespace std;
int n,l[100001],r[100001],L,R,p,maxx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>l[i]>>r[i];
        L+=l[i];
        R+=r[i];
    }
    maxx=abs(L-R);
    for(int i=1;i<=n;++i)
    {
        if(abs(L-l[i]+r[i]-(R-r[i]+l[i]))>maxx)
        {
            p=i;
            maxx=abs(L-l[i]+r[i]-(R-r[i]+l[i]));
        }
    }
    cout<<p;
    return 0;
}
