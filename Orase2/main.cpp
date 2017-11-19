#include <iostream>
#include <fstream>
#include <math.h>
#define NM 50005
using namespace std;
ifstream in("orase2.in");
ofstream out("orase2.out");
int n,d[NM],v[NM],x,t,sum,k[NM];
double B,st=0,dr=100000000,timp;
int main()
{
    in>>t;
    in>>n>>x;
    for(int i=1;i<=n;++i)in>>d[i];
    for(int i=1;i<=n;++i)in>>v[i];
    while(sum!=x)
    {
        B=(st+dr)/2.0;
        sum=0;
        for(int i=1;i<=n;++i)
            k[i]=(int)(d[i]*1.0/B-v[i]);
        for(int i=1;i<=n;++i)
            sum+=k[i];
        if(sum>x)st=B;
        else dr=B;
    }
    for(int i=1;i<=n;++i)
        timp+=1.0*d[i]/(v[i]+k[i]);
    out<<(int)(timp);
    return 0;
}
///  caut valoarea minima pentru ultima diferenta ca sa ajung acolo
///  d/(v+k-1)(v+k)>=B
