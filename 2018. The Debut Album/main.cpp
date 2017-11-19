#include <iostream>

using namespace std;
long long n,sa[301],sb[301],a,b,suma,sumb,x;
int main()
{
    cin>>n>>a>>b;
    sa[1]=1;
    sb[1]=1;
    for(int j=1;j<n;++j)
    {
        suma=sa[1];
        sumb=sb[1];
        for(int i=a;i>1;--i)
        {
            suma=(suma+sa[i])%1000000007;
            sa[i]=sa[i-1];
        }
        for(int i=b;i>1;--i)
        {
            sumb=(sumb+sb[i])%1000000007;
            sb[i]=sb[i-1];
        }
        x=sa[1];
        sa[1]=sumb%1000000007;
        sb[1]=suma%1000000007;
    }
    suma=0;
    sumb=0;
    for(int i=a;i>=1;--i)
    {
        suma=(suma+sa[i])%1000000007;
    }
    for(int i=b;i>=1;--i)
    {
        sumb=(sumb+sb[i])%1000000007;
    }
    cout<<(suma+sumb)%1000000007;
    return 0;
}
