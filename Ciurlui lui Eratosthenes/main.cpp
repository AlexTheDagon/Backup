#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;
ifstream in("ciur.in");
ofstream out("ciur.out");
int n,nr;
bitset <2000005> b;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)b[i]=1;
    for(int i=2;i<=n;++i)
    {
        if(b[i])
        {
            for(int j=i+i;j<=n;j+=i)b[j]=0;
            ++nr;
        }
    }
    out<<nr;
    return 0;
}
