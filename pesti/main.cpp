#include <iostream>
#include <fstream>
using namespace std;
ifstream in("pesti.in");
ofstream out("pesti.out");
int n,x,g,z,xprim,zprim,k;
int main()
{
    in>>n>>x;
    g=n;
    while(g>2)
    {
        ++z;
        g=g-g/2;
    }
    k=n;
    for(int i=1;i<=z;++i)
    {
        if(x%2==0)x=n-n/2+x/2;
        else
    }
    return 0;
}
