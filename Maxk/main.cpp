#include <iostream>
#include <fstream>
using namespace std;
ifstream in("maxk.in");
ofstream out("maxk.out");
int n,k,a[100010],nr,x;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>x;
        a[x]++;
    }
    for(int i=1;i<=100002;++i)
    {
        nr+=max(a[i]-k,0);
    }
    out<<nr;
    return 0;
}
