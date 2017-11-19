#include <iostream>
#include <fstream>
using namespace std;
ifstream in("fences.in");
ofstream out("fences.out");
string s;
long long u,d,l,r;
int t;
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        u=0;
        d=0;
        l=0;
        r=0;
        in>>s;
        for(auto c:s)
        {
            if(c=='U')++u;
            if(c=='D')++d;
            if(c=='L')++l;
            if(c=='R')++r;
        }
        out<<min(r,l)*min(u,d)<<'\n';
    }
    return 0;
}
