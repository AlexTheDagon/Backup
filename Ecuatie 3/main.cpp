#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
ifstream in("ecuatie3.in");
ofstream out("ecuatie3.out");
long long n,t;
long long d;
vector <long long> v;
long long combinari(long long nn,long long k)
{
    long long n1=1,kp=1,kn=1;
    long long ii=2;
    for(long long i=k+1;i<=nn;++i)
    {
        n1*=i;
        if(n1%ii==0 && ii<=nn-k)
        {
            n1/=ii;
            ++ii;
        }
    }
    return n1;
}
int main()
{
    in>>n>>t;
    d=1;
    long long diviz=0;
    long long limit=sqrt(n)+2;
    while(t>1 && d<=limit)
    {
        ++d;
        diviz=0;
        while(t%d==0)
        {
            t/=d;
            ++diviz;
        }
        if(diviz!=0)v.pb(diviz);
    }
    if(t>1)v.pb(1);
    long long sol=1;
    for(auto i:v)
    {
        sol*=combinari(n+i-1,i);
    }
    out<<sol;
    return 0;
}
