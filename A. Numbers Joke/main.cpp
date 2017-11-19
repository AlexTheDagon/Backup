#include <iostream>

using namespace std;
int a[100],b;
void mul(int c)
{
    int i,t=0;
    for(i=1;i<=a[i] || t;++i,t/=10)
    {
        a[i]=(t+=a[i]*b)%10;
    }
    a[0]=i-1;
}
int main()
{
    cin>>b;
    a[1]=1;
    a[0]=1;
    for(int i=1;i<=b;++i)mul(b);
    for(int i=a[0];i>0;--i)cout<<a[i];
    return 0;
}
