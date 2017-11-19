#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ssm.in");
ofstream out("ssm.out");
int a,smax=-2000000000,s=-1,imin,mini,imax,n;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a;
        if(s<0)
        {
            s=a;
            imin=i;
        }
        else s=s+a;
        if(s>smax)
        {
            mini=imin;
            smax=s;
            imax=i;
        }
    }
    out<<smax<<" "<<mini<<" "<<imax;
    return 0;
}
