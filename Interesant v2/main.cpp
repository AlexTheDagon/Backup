#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
ifstream in("interesant.in");
ofstream out("interesant.out");
string a[201];
int n,x[201],v,l,nr,lmax;
int main()
{
    in>>v>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        if(a[i].size()>lmax)
        {
            lmax=a[i].size();
            l=i;
        }
    }
    if(v==1)
    {
        for(int i=1;i<n;++i)
        {
            if(a[i].size()==lmax && a[i]<a[l])l=i;
        }
        out<<a[l];
    }
    else
    {
        for(int i=1;i<=n;++i)x[i]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(j!=i)
                {
                    if(x[j]==1 && a[i].size()<a[j].size())
                    {
                        l=0;
                        for(int k=0;k<a[j].size();++k)
                        {
                            if(a[i][l]==a[j][k])++l;
                        }
                        if(l==a[i].size())x[i]=0;
                    }
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(x[i]==1)++nr;
        }
        out<<nr<<'\n';
        for(int i=1;i<=n;++i)
        {
            if(x[i]==1)out<<a[i]<<'\n';
        }
    }
    return 0;
}
