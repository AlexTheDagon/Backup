#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int main()
{
    int n,x;
    in>>n;
    bitset<1000> a;
    for(int i=1;i<=n;i++)
    {
        in>>x;
        a[x]=1;
    }
    for(int i=0;i<=1000;i++)
    {
        if(a[i]==1)out<<i<<" ";
    }

    return 0;
}
