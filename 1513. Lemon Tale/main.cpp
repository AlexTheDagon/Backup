#include <iostream>

using namespace std;
long long a[20050],b,ind,n,k,sa,sb;
int main()
{
    cin>>n>>k;
    if(k==0)
    {
        cout<<"1";
        return 0;
    }
    ind=10005+n;
    a[ind]=1;
    b=1;
    sa=1;
    sb=1;
    for(int i=2;i<=n;++i)
    {
        --ind;
        sb=b;
        b+=sa;
        sa-=a[ind+k];
        a[ind]=sb;
        sa+=sb;
    }
    cout<<b+sa;
    return 0;
}
