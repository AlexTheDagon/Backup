#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("interesant.in");
ofstream out("interesant.out");
int n,l,nrsiruri,lmax,v,sem[201];
string s[201],sir;
int main()
{
    in>>v>>n;
    for(int i=1;i<=n;++i)
    {
        in>>s[i];
    }
    if(v==1)
    {
        sort(s+1,s+n+1);
        for(int i=1;i<=n;++i)
        {
            if(s[i].size()>lmax)
            {
                lmax=s[i].size();
                sir=s[i];
            }
        }
        out<<sir;
    }
    else
    {
        for(int i=1;i<=n;++i)sem[i]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j)
                {
                    if(sem[j]==1 && s[i].size()<s[j].size())
                    {
                        l=0;
                        for(int k=0;k<s[j].size();++k)
                        {
                            if(s[i][l]==s[j][k])++l;
                        }
                        if(l==s[i].size())sem[i]=0;
                    }
                }
            }
        }
        for(int i=1;i<=n;++i)if(sem[i])++nrsiruri;
        out<<nrsiruri;
        for(int i=1;i<=n;++i)
        {
            if(sem[i])out<<'\n'<<s[i];
        }
    }
    return 0;
}
