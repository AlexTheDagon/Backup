#include <iostream>
#include <fstream>
using namespace std;
ifstream in("combinari.in");
ofstream out("combinari.out");
int n,a[100], fol[100],k,x;
void afisare(int p)
{
    if(p>k)
    {
        for(int i=1;i<=k;++i)out<<a[i]<<" ";
        out<<'\n';
        return;
    }
    for(int l=a[p-1]+1;l<=n;++l)
    {
        if(fol[l]==0)
        {
            a[p]=l;
            fol[l]++;
            afisare(p+1);
            fol[l]--;
        }
    }
}
int main()
{
    in>>n>>k;
    afisare(1);
    return 0;
}
