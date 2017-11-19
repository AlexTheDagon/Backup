#include <iostream>
#include <fstream>
using namespace std;
ifstream in("teatru.in");
ofstream out("teatru.out");
int n,c,is,jfin,istmax,ifinmax,maxx,r,fr[150];
string s;
int main()
{
    in>>n>>c;
    in>>s;
    r=c;
    is=0;
    for(int i=0;i<n;++i)
    {
        if(fr[s[i]])++fr[s[i]];
        else
        {
            if(r)
            {
                ++fr[s[i]];
                --r;
            }
            else
            {
                while(!r)
                {
                    --fr[s[is]];
                    if(fr[s[is]]==0)++r;
                    ++is;
                }
                ++fr[s[i]];
                --r;
            }
        }
        if(i-is+1>maxx)
        {
            maxx=i-is+1;
            ifinmax=i;
            istmax=is;
        }
    }
    out<<maxx<<'\n';
    for(int i=istmax;i<=ifinmax;++i)out<<s[i];
    return 0;
}
