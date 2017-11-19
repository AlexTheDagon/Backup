#include <iostream>
#include <fstream>
using namespace std;
ifstream in("permutari.in");
ofstream out("permutari.out");
int k,a[10],fol[10];
void gen(int p)
{
    if(p==k+1)
    {
        for(int i=1;i<=k;++i)out<<a[i]<<" ";
        out<<'\n';
    }
    else
    {
        for(int i=1;i<=k;++i)
        {
            if(fol[i]==0)
            {
                fol[i]=1;
                a[p]=i;
                gen(p+1);
                fol[i]=0;
            }
        }
    }
}
int main()
{
    in>>k;
    gen(1);
    return 0;
}
