#include <iostream>
#include <fstream>
using namespace std;
ifstream in("prim.in");
ofstream out("prim.out");
int a[1400100];
long long x,nr=2,p,k;
int main()
{
    in>>k;
    for(int i=2;i<=1400000;++i)a[i]=1;
    for(int i=2;i<=1400000;++i)
    {
        if(a[i]==1)
        {
            nr++;
            for(int j=i+i;j<=1400000;j=j+i)a[j]=0;
        }
    }
    int nrp=0;
    for(int i=2;p==0;++i)
    {
        if(a[i]==1)nrp++;
        if(nrp==k+1)p=i;
    }
    cout<<p;
    x=p*p;
    out<<x;

    return 0;
}
