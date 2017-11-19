#include <iostream>
#include <fstream>
#define prim 1999999973
using namespace std;
ifstream in("lgput.in");
ofstream out("lgput.out");
long long n,a,sol=1;
int main()
{
    in>>a>>n;
    for(int i=0;(1<<i)<=n;++i)
    {
        if(n&(1<<i))sol=sol*a;
        a*=a;
        a%=prim;
        sol%=prim;
    }
    out<<sol;
    return 0;
}
