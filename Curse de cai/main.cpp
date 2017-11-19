#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cai.in");
ofstream out("cai.out");
long long a[1005],b[1005],p,n,t,g,io,sarit;
int main()
{
    in>>t;
    for(int k=1;k<=t;++k)
    {
        in>>n;
        sarit=0;
        for(int i=1;i<=n;++i)in>>a[i];
        for(int i=1;i<=n;++i)in>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        g=n,io=n;
        p=0;
        while(io)
        {
            if(a[g]>=b[io])
            {
                if(a[g]>b[io])p+=200;
                else
                {
                    if(a[g]>b[io-1] && io>1)
                    {
                        p+=200;
                        --io;
                        ++sarit;
                    }
                }
                --g;
            }
            else p-=200;
            --io;
        }
        out<<p-200*sarit<<'\n';
    }
    return 0;
}
