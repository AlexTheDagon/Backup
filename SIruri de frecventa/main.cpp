#include <iostream>
#include <fstream>
using namespace std;
ifstream in("fsb.in");
ofstream out("fsb.out");
int n,a[200000],s,c[100];
char v;
int main()
{in>>n;
for(int i=1;i<=n;i++)
{
    in>>v;
    if(v=='0')a[i]=a[i-1]-1;
    else a[i]=a[i-1]+1;
    ++c[a[i]];
}
for(int i=0;i<n;i++)
{
    if(c[i]>=2)
    s=s+c[i];
}
out<<s;

    return 0;
}
