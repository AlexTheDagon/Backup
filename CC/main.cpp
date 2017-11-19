#include <iostream>
#include <stdlib.h>
using namespace std;
int a[100005],n,poz[100005],smars[100005],p,d[100005],in[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;++i)
    {
        cin>>a[i];
        if(poz[a[i]])
        {
            ++d[poz[a[i]]];
            ++in[i];
        }
        else poz[a[i]]=i;
    }
    for(int i=1;i<=2*n;++i)
    {
        d[i]+=d[i-1];
        in[i]+=in[i-1];
    }
    for(int i=1;i<=2*n;++i)
        if(poz[a[i]]!=i)p+=(d[poz[a[i]]]-in[i]);
    cout<<p;
    return 0;
}
