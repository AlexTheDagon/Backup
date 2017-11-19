#include <iostream>
#include <fstream>
using namespace std;
ifstream in("scmax.in");
ofstream out("scmax.out");
int n,s[100001],l[100001],ant[100001],b[100001],maxx,lmax,c,k;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>s[i];
    for(int i=1;i<=n;++i)
    {
        maxx=0;
        for(int j=1;j<=i-1;++j)
        {
            if(s[i]>s[j] && l[j]>maxx)
            {
                maxx=l[j];
                ant[i]=j;
            }
        }
        l[i]=maxx+1;
        if(l[i]>lmax)
        {
            lmax=l[i];
            k=i;
        }
    }
    out<<lmax<<'\n';
    c=lmax;
    for(int j=k;c>0;j=ant[j])
    {
        b[c]=s[j];
        --c;
    }
    for(int i=1;i<=lmax;++i)out<<b[i]<<" ";
    return 0;
}
