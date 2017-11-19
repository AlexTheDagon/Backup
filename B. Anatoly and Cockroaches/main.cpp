#include <iostream>

using namespace std;
int n,nr,r1,n1,r2,n2,a[100001],s;
char c;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>c;
        if(c=='r')a[i]=1;
        else a[i]=2;
    }
    for(int i=1;i<=n;i=i+2)
    {
        if(a[i]==1)r1++;
        else n1++;
    }
    for(int i=2;i<=n;i=i+2)
    {
        if(a[i]==1)r2++;
        else n2++;
    }
    if(r1>r2)
    {
        if(r1+r2>(n+1)/2)nr=r2;
        else nr=(n+1)/2-r1;
    }
    else
    {
        if(n1+n2>(n+1)/2)nr=n2;
        else nr=(n+1)/2-n1;
    }
    cout<<nr;
    return 0;
}
