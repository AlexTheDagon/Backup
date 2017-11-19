#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ksplit.in");
ofstream out("ksplit.out");
long long a[100005],smax1=-2000000000,s1=-1,imax1,imin1,mini1,l1,smax2=-2000000000,s2=-1,imax2,imin2,mini2,l2,n;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=1;i<=n;++i)
    {
        if(s1<0)
        {
            s1=a[i];
            imin1=i;
        }
        else s1=s1+a[i];
        if(s1>smax1)
        {
            mini1=imin1;
            smax1=s1;
            imax1=i;
        }
    }
    cout<<smax1;
    return 0;
}
