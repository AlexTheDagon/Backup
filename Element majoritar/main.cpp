#include <iostream>
#include <fstream>
using namespace std;
ifstream in("elmaj.in");
ofstream out("elmaj.out");
int x,cur,ap,n,a[1000005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        if(a[i]!=cur)--ap;
        else ++ap;
        if(ap<0)
        {
            ap=1;
            cur=a[i];
        }
    }
    ap=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==cur)++ap;
    }
    if(ap>=n/2+1)out<<cur<<" "<<ap;
    else out<<"-1";
    return 0;
}
