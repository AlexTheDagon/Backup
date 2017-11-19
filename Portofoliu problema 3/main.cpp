#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("NUMERE.IN");
ofstream out("NUMERE.OUT");
int n;
int prim(int p)
{
    for(int i=2;i<=sqrt(p);++i)if(p%i==0)return 0;
    return 1;
}
int main()
{
    ///a)
    in>>n;
    out<<prim(n)<<'\n';
    ///b)
    in>>n;
    for(int i=2;n>0;++i)
    {
        if(prim(i))
        {
            out<<i<<" ";
            --n;
        }
    }
    return 0;
}
