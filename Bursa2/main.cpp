#include <iostream>
#include <fstream>
using namespace std;
ifstream in("bursa.in");
ofstream out("bursa.out");
long long n,s,p[100002],sprim;
int main()
{
    in>>n>>s;
    sprim=s;
    p[0]=10000000000;
    for(int i=1;i<=n;++i)
    {
        in>>p[i];
        if(p[i]>p[i-1])s=s%p[i-1]+s/p[i-1]*p[i];
    }
    out<<s-sprim;
    return 0;
}
