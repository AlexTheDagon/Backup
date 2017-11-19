#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("pluton.in");
ofstream out("pluton.out");
string s[4005],cod[4005],sol;
int n,maxx,nrmax,viz[4004],nr[4005],refacut;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>s[i];
        cod[i]=s[i];
        sort(cod[i].begin(),cod[i].end());
    }
    for(int i=1;i<=n;++i)
    {
        nr[i]=1;
        if(viz[i]==0)
        {
            viz[i]=1;
            ++refacut;
            for(int j=i+1;j<=n;++j)
            {
                if(cod[i]==cod[j])
                {
                    ++nr[i];
                    viz[j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(nr[i]>maxx)
        {
            maxx=nr[i];
            nrmax=0;
            sol=cod[i];
        }
        if(nr[i]==maxx)++nrmax;
    }
    out<<refacut<<'\n';
    out<<maxx<<'\n';
    out<<nrmax<<'\n';
    for(int i=1;i<=n;++i)
    {
        if(cod[i]==sol)out<<s[i]<<" ";
    }
    return 0;
}
