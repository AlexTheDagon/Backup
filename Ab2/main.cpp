#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ab2.in");
ofstream out("ab2.out");
int n,a,b,s[30005],aux;
int main()
{
    in>>n>>a>>b;
    for(int i=a-1;i>=0;--i)
    {
        s[i]=min(n-i,b);
        n-=s[i];
    }
    for(int i=0;i<a;++i)
    {
        for(int j=n+s[i];j>n;--j)out<<j<<" ";
        n+=s[i];
    }
    return 0;
}
