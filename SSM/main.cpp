#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ssm.in");
ofstream out("ssm.out");
int a[6000001],minn=2000000000,mini,maxx=-2000000000,maxi,l=60000000,n,minip,maxip,s=-200000000;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]<minn)
        {
            minn=a[i];
            mini=i;
        }
        if((a[i]-minn)>s)
        {
            s=a[i]-minn;
            maxi=i;
        }
    }
    out<<s<<" "<<mini+1<<" "<<maxi;
    return 0;
}
