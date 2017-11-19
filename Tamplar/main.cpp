#include <iostream>
#include <fstream>
using namespace std;
ifstream in("tamplar.in");
ofstream out("tamplar.out");
long long n,a[10000],sol=1,x;
void mul(int b)
{
    int t=0,ii=1;
    for(ii=1;ii<=a[0] || t;++ii,t/=10000)
    {
        a[ii]=(t+=a[ii]*b)%10000;
    }
    a[0]=ii-1;
}
int main()
{
    in>>n;
    a[0]=1;
    a[1]=2;
    for(int i=4;i<=n;++i)mul(i-1);
    out<<a[a[0]];
    for(int i=a[0]-1;i>0;--i)
    {
        if(a[i]<10)out<<"000";
        else
        {
            if(a[i]<100)out<<"00";
            else if(a[i]<1000)out<<"0";
        }
        out<<a[i];
    }
    return 0;
}
