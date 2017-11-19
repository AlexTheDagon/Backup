#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sumdiv2.in");
ofstream out("sumdiv2.out");
long long ciur[1000005],s[1000005],n,a,b,q;
int main()
{
    in>>q;
    for(int i=1;i<=1000002;++i)
    {
        for(int j=i;j<=1000002;j+=i)s[j]+=i;
    }
    for(int i=1;i<=1000002;++i)s[i]+=s[i-1];
    for(int i=1;i<=q;++i)
    {
        in>>a>>b;
        out<<s[b]-s[a-1]<<'\n';
    }
    return 0;
}
