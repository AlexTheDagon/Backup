#include <iostream>

using namespace std;
int n,p,sa,sb,a,b;
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        sa+=a;
        sb+=b;
    }
    if(sa<=p)cout<<"-1";
    else
    {
        cout<<1.0*sb/(sa-p);
    }
    return 0;
}
