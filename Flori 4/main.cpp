#include <iostream>
#include <fstream>
using namespace std;
ifstream in("flori4.in");
ofstream out("flori4.out");
int n,a[10005],s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)a[i]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=i-2;j>0;--j)a[i]+=a[j];
        a[i]%=9001;
    }
    for(int i=1;i<=n;++i)
    {
        s+=a[i];
    }
    out<<s%9001;
    return 0;
}
