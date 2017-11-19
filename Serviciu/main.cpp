#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("serviciu.in");
ofstream out("serviciu.out");
int n,x,y,maxx,lmax;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y;
        lmax=max(lmax,min(abs(x-y),2*n-abs(x-y)));
    }
    out<<lmax;

    return 0;
}
