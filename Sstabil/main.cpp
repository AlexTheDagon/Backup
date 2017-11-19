#include <iostream>
#include <fstream>
#define NM 1000005
using namespace std;
ifstream in("sstabil.in");
ofstream out("sstabil.out");
int a[NM],b[NM],n,ii,t,k,s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    a[0]=a[n+1]=b[0]=9;
    k=0;
    while(n>0)
    {
        ii=n;
        s=0;
        do
        {
            s+=a[ii];
            --ii;
        }
        while(s<10);
        ii=n;
        t=a[n];
        while(s-t>9 || t+b[k]<10)
        {
            --ii;
            t+=a[ii];
        }
        b[++k]=t;
        n=ii-1;
    }
    for(int i=k;i>0;--i)out<<b[i];
    return 0;
}
///ajutor
