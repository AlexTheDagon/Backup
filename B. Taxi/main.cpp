#include <iostream>

using namespace std;
int a[5],x,n,c;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        a[x]++;
    }
    c=c+a[4];
    a[4]=0;
    c=c+a[3];
    a[1]=a[1]-a[3];
    a[3]=0;
    if(a[2]>0)c=c+a[2]/2;
    if(a[1]>0)c=c+a[1]/4;
    a[2]=a[2]-a[2]/2*2;
    a[1]=a[1]-a[1]/4*4;
    if(a[2]>0)
    {
        c++;
        a[1]=a[1]-2;
    }
    if(a[1]>0)c++;
    cout<<c;
    return 0;
}
