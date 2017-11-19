#include <iostream>
#include <fstream>
using namespace std;
ifstream in("patrate2.in");
ofstream out("patrate2.out");
int a[100000];
int n;
void mult(int b)
{
    int i=1,t=0;
    for(i=1;i<=a[0] || t;++i,t/=10)
    {
        a[i]=(t+=a[i]*b)%10;
    }
    a[0]=i-1;
}
int main()
{
    in>>n;
    a[0]=1;
    a[1]=1;
    for(int i=1;i<=n;++i)mult(2*i);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=(n-1)/3;++j)mult(8);
        for(int j=1;j<=(n-1)%3;++j)mult(2);
    }
    for(int i=a[0];i>0;--i)out<<a[i];
    return 0;
}
