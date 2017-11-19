#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;
ifstream in("bunicu.in");
ofstream out("bunicu.out");
bitset <1005> a,b;
int t,n;
char c;
int main()
{
    in>>t;
    for(int T=0;T<t;++T)
    {
        in>>n;
        for(int i=1;i<=n;++i)b[i]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                in>>c;
                if(c=='1')a[j]=1;
                else a[j]=0;

            }
            out<<1-a[i];
        }
        out<<'\n';
    }
    return 0;
}
